#pragma once
#include <map>
#include <exception>
#include <iostream>
#include <memory>
/*********************************************************************************/
/*****************************<UNIQUE POINTER>************************************/
template <class T>
class UniquePointer
{
public:
	UniquePointer(T *p) : _ptr(p) {}
	~UniquePointer()
	{ /*Add your code*/
		delete _ptr;
	}
	UniquePointer(const UniquePointer<T> &p) = delete;					   //Disable copy constructor
	const UniquePointer<T> &operator=(const UniquePointer<T> &p) = delete; //disable = operator
	UniquePointer(/*Add your code*/ UniquePointer<T> &&p)				   //Create move semantics for rvalue referance
	{
		_ptr = p._ptr;
		p._ptr = nullptr;
		/*Code Added*/
	}

	const T &operator*() const
	{
		//CODE ADDED
		if (nullptr != _ptr)
			return *_ptr;
		return NULL;
	}
	T *operator->() const
	{
		if (nullptr != _ptr)
			return _ptr /*Code Added*/;

		return NULL;
	}

private:
	/*CODE ADDED*/
	T *_ptr;
};

/*********************************************************************************/
/*****************************<SHARED POINTER>************************************/
class Counter
{
public:
	Counter() : _useCount(0), _weakCount(0) {}
	Counter(int use, int weak) : _useCount(use), _weakCount(weak) {}

public:
	void incUse()
	{ /*Add your code*/
		++_useCount;
	}
	void incWeak() { ++_weakCount; }
	void decUse() { --_useCount; }
	void decWeak() { --_weakCount; }
	int getUse() const { return _useCount; }
	int getWeak() const { return /*Add your code*/ _weakCount; }

private:
	int _useCount;
	int _weakCount;
};

template <class T>
class SharedPointer
{
public:
	SharedPointer(T *p) : _ptr(p), _counter(new Counter(1, 0)) /*we need to make a reference counting because it will be shared among others*/ {}

	~SharedPointer()
	{
		decrementRef();
	}

	SharedPointer(const SharedPointer<T> &p)
	{
		_counter = nullptr;
		*this = p; //Call = operator
	}

	const SharedPointer<T> &operator=(const SharedPointer<T> &p)
	{
		/*CODE ADDED*/
		decrementRef();
		_counter = p._counter;
		_ptr = p._ptr;
		_counter->incUse();
		return *this;
	}
	const T &get() { return *_ptr; }

	template <class U>
	friend class WeakPointer;

private:
	// I ADDED the method to decrease each shared counter that points to the same pointer
	void decrementRef()
	{
		if (_counter == nullptr)
			return;
		_counter->decUse();			 //Decrement the reference counter
		if (_counter->getUse() == 0) // we need to check also that weak counter is 0 because as shared ptr we are not allowed to delete the ptr as long as the weak count and the use count is not 0
		{
			delete _ptr;
			if (_counter->getWeak() == 0)
				delete _counter;
		}
	}

	const T &operator*() const { return *_ptr; }
	T *operator->() const { return _ptr; }

private:
	/*CODE ADDED*/
	T *_ptr;
	Counter *_counter;
};

/*********************************************************************************/
/******************************<WEAK POINTER>************************************/

template <class T>
class WeakPointer
{
public:
	WeakPointer() : _shared(nullptr), _counter(nullptr) {}

	WeakPointer(SharedPointer<T> &p) : _shared(&p), _counter(p._counter)
	{
		/*CODE ADDED*/
		_counter->incWeak();
	}

	~WeakPointer()
	{
		decrementRef();
	}

	WeakPointer(const WeakPointer<T> &wp)
	{
		_counter = nullptr;
		*this = wp;
	}

	const WeakPointer<T> &operator=(const WeakPointer<T> &WeakPointer)
	{
		decrementRef();
		_counter = WeakPointer._counter;
		_shared = WeakPointer._shared;
		_counter->incWeak();
		return *this;
	}

	bool expired() const { return _counter->getUse() == 0; }

	T *operator->() const
	{
		if (/*CODE ADDED*/ expired())
			throw "Pointer is not longer valid.";
		return _shared;
	}

	const T &operator*() const
	{
		if (expired())
			throw "Pointer is not longer valid.";
		return **_shared;
	}

private:
	/*Add your code -- Started*/
	void decrementRef(void)
	{
		if (_counter == nullptr)
			return;
		_counter->decWeak();
		if (expired() && _counter->getWeak() == 0)
		{
			delete _counter;
		}
	}

private:
	SharedPointer<T> *_shared;
	Counter *_counter;
};
/*PART B*/

template <class K, class V>
class CacheMemory
{
public:
	void add(const K &key, const V &value)
	{
		// not found
		if (map1.find(key) == map1.end())
		{
			//SharedPointer<V> added(new V(value));
			std::shared_ptr<V> added(new V(value));
			map1[key] = added;
		}
		// found
		else
			throw "DuplicateKeyException";
	}
	void erase(const K &key)
	{
		if (map1.find(key) != map1.end())
			map1.erase(key);
		else
			throw "ObjectNotExistException";
	}
	std::shared_ptr<V> get(const K &key)
	{
		try
		{
			//Check if value exists for the particular key
			auto entry = mapCache.find(key);
			if (entry != mapCache.end())
			{
				//key found
				if (!mapCache[key].expired())
				{
					return mapCache[key].lock();
				}
			}
			else if (map1.find(key) != map1.end())
			{
				//found in map1 the key
				mapCache[key] = map1[key]; // we insert the value to mapCache
				return map1[key];
			}
			else
			{
				std::cout << "Not found" << std::endl;
				return nullptr;
			}
		}
		catch (...)
		{
			mapCache.erase(key);
		}
	}

private:
	std::map<K, std::shared_ptr<V>>
		map1;
	std::map<K, std::weak_ptr<V>> mapCache;
};

class Employee
{
private:
	char *id;
	int salary;
	int seniority;
};