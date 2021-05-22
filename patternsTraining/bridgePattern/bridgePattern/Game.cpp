#include "Game.h"
Game::Game(Moveable* type, int difficulty , int sizeBoard) {
	m_type = type;
	m_difficulty = difficulty;
	m_sizeBoard = sizeBoard;
	m_mat = new int*[sizeBoard];
	for (int i = 0; i < sizeBoard; ++i)
		m_mat[i] = new int[sizeBoard];
}
Game::~Game() {
	for (int i = 0; i < m_sizeBoard; ++i)
		delete[] m_mat[i];
	delete m_type;
}
int Game::getDifficulty()
{
	return m_difficulty;
}
int** Game::getMat() {
	return m_mat;
}
int Game::getSizeBoard() {
	return m_sizeBoard;
}