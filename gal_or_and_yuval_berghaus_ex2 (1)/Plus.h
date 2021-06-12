#pragma once
#include "BinaryExpression.h"
class Plus : public BinaryExpression
{
public:
	Plus(Expression* left, Expression* right) :BinaryExpression(left, right) { ; }
	virtual double calculate() { return getLeft() + getRight(); }
};