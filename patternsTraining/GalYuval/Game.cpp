#include "Game.h"
Game::Game(Moveable* type, int difficulty , int sizeBoard) {
	m_type = type;
	m_difficulty = difficulty;
	mat = new int*[sizeBoard];
	for (int i = 0; i < sizeBoard; ++i)
		mat[i] = new int[sizeBoard];
}

int Game::getDifficulty()
{
	return m_difficulty;
}
