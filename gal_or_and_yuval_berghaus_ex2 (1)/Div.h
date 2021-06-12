#pragma once
#include "BinaryExpression.h"
class Div : public BinaryExpression
{
public:
	Div(Expression* left, Expression* right) : BinaryExpression(left, right) { ; }
	virtual double calculate() { return getLeft() / getRight(); }
};