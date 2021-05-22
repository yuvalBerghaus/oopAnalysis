#include "TicTacToe.h"
void TicTacToe::moveHim() {
	m_type->move(getMat() , getSizeBoard() , getDifficulty());
}
TicTacToe::TicTacToe(Moveable* type, int difficulty,int sizeBoard):Game(type, difficulty, sizeBoard) 
{
}