#pragma once
class Moveable
{
public:
	Moveable() {};
public:
	virtual void move(int**mat , int difficulty) = 0;
};