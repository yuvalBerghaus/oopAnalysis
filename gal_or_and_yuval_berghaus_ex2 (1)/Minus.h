#pragma once
#include "BinaryExpression.h"
class Minus : public BinaryExpression
{
public:
	Minus(Expression* left, Expression* right) : BinaryExpression(left, right) { ; }
	virtual double calculate() { return getLeft() - getRight(); }
};