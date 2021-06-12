#include "Game.h"
#include "TicTacToe.h"

class TicTacToe_Normal : public TicTacToe
{
public:
	TicTacToe_Normal(/*string state = "123456789"*/int sizeBoard) :TicTacToe(sizeBoard) {};

	void playerMove();
	void computerMove();
};

