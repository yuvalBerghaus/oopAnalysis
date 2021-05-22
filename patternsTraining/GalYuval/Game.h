#pragma once
#include "Moveable.h"
class Game
{
private:
	int m_difficulty;
	int** mat;
protected:
	Moveable* m_type;
public:
	Game(Moveable* type, int difficulty, int sizeBoard);
	~Game() {};
public:
	int** getMat();
	int getDifficulty();
	virtual void moveHim() = 0;
	
};

