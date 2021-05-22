#pragma once
class Moveable
{
public:
	Moveable() {
		
	};
public:
	virtual void move(int** mat, int sizeBoard, int difficulty) = 0;
};