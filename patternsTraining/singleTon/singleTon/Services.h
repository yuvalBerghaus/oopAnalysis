#pragma once
class Services
{
private:
	static Services* obj;
	int age;
	char level;
private:
	Services(int,char);
public:
	~Services() {};
	int getAge();
	char getLvl();
	void setAge(int m_age);
	void setLvl(char m_level);
	static Services* getInstance(int m_age = 0, char m_level = 'A');
};