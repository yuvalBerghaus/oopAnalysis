#pragma once
#include "Moveable.h"
class Game
{
private:
	int m_difficulty;
	int** m_mat;
	int m_sizeBoard;
protected:
	Moveable* m_type;
public:
	Game(Moveable* type, int difficulty, int sizeBoard);
	~Game();
public:
	int** getMat();
	int getDifficulty();
	int getSizeBoard();
	virtual void moveHim() = 0;
};

