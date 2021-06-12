#pragma once
#include "Expression.h"
#include "Number.h"
class BinaryExpression : public Expression
{
public:
	BinaryExpression() = delete;
	~BinaryExpression() { delete _left; delete _right; }
	BinaryExpression(Expression* left, Expression* right) { _left = left; _right = right; }
	double getLeft() { return _left->calculate(); }
	double getRight() { return _right->calculate(); }
	virtual double calculate() = 0;
private:
	Expression* _left; // number / binary expression
	Expression* _right;
};

