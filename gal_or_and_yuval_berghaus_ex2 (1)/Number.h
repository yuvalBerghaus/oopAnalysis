#pragma once
#include "Expression.h"

class Number : public Expression
{
public:
	Number(double x) { _value = x; }
	virtual double calculate() { return _value; }
private:
	double _value;
};

