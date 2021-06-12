#pragma once
#include "BinaryExpression.h"
class Mul : public BinaryExpression
{
public:
	Mul(Expression* left, Expression* right) :BinaryExpression(left, right) { ; }
	virtual double calculate() { return getLeft() * getRight(); }
};