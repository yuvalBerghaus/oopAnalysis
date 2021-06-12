#include "BinaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"

void main()
{
	Expression* Ex10 = new Number(10);
	Expression* Ex2 = new Number(2);
	Expression* Ex3 = new Number(3);
	Expression* Ex4 = new Number(4);

	Div* d1 = new Div(Ex10, Ex2);
	Minus* min1 = new Minus(Ex3, Ex4);
	Mul* mul1 = new Mul(Ex2, min1);
	Plus* plus1 = new Plus(d1, mul1);

	double check = plus1->calculate();
	cout << check;
}