#include "Game.h"
#include "TicTacToe.h"

class TicTacToe_Hard : public TicTacToe
{
public:
	TicTacToe_Hard(int difficult = 3, string state = "123456789");

	void playerMove();
	void computerMove();
};

