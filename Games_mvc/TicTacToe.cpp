#include "TicTacToe.h"
bool TicTacToe::checkWinner() { // We'll use _board int
	int count_TTB = 0;
	int count_BBT = 0;
	// first index reperesents our player type. if -1 then player, if 1 then computer else 0 empty field
	int firstIndex;
	int firstIndexDiagonalTTB = _board[0][0];
	int firstIndexDiagonalBTT = _board[_boardSize - 1][0];;
	int i, j;
	for (i = 0; i < _boardSize; i++) {
		for (j = 0; j < _boardSize; j++) { // Here we check per row
			if (j == 0) {
				firstIndex = _board[i][j];
			}
			if (firstIndex != _board[i][j]) {
				break;
			}
		}
		if (j == _boardSize) {
			//Our winner is type state of current firstIndex
			return true;
		}
		for (j = 0; j < _boardSize; j++) { // Here we check per col
			if (j == 0) {
				firstIndex = _board[j][i];
			}
			if (firstIndex != _board[j][i]) {
				break;
			}
		}
		if (j == _boardSize) {
			//Our winner is type state of current firstIndex
			return true;
		}
		if (firstIndexDiagonalTTB == _board[i][i]) {
			count_TTB++;
		}
		if (firstIndexDiagonalBTT == _board[_boardSize - 1 - i][i]) {
			count_BBT++;
		}
	}
	if (count_BBT == i) {
		return true;
	}
	else if (count_TTB == i) {
		return true;
	}
}
bool TicTacToe::checkValidation() {

}