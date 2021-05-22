#include "Services.h"
#include <iostream>
using namespace std;
int Services::getAge()
{
	return age;
}

char Services::getLvl()
{
	return level;
}

void Services::setAge(int m_age)
{
	age = m_age;
}

void Services::setLvl(char m_level)
{
	level = m_level;
}

Services* Services::getInstance(int m_age,char m_level) {
	if (obj == nullptr) {
		Services::obj = (new Services(m_age,m_level));
		cout << "the object was created first time!";
	}
	return Services::obj;
};

Services::Services(int m_age, char m_level) {
	age = m_age;
	level = m_level;
};

Services* Services::obj = nullptr;