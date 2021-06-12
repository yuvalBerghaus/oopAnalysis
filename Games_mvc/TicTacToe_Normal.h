#include "Game.h"
#include "TicTacToe.h"

class TicTacToe_Normal : public TicTacToe
{
public:
	TicTacToe_Normal(int difficult = 3, string state = "123456789");

	void playerMove();
	void computerMove();
};

