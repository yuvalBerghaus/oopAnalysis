#include "Game.h"

class TicTacToe : public Game
{
public:
	TicTacToe(int difficult, string state);
	virtual void playerMove();
	virtual void computerMove();
	virtual void setBoard(int index);
	virtual void setState(string);
	void getWinner() { return winner; }
};

