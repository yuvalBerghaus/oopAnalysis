#include "Game.h"
Game::Game(int boardSize) {
	_boardSize = boardSize;
	_board = new int* [boardSize]; // Allocating rows
	for (int i = 0; i < boardSize; i++) {
		_board[i] = new int[boardSize]; // allocating cols
	}
}