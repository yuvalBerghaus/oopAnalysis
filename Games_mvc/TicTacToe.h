#include "Game.h"

class TicTacToe : public Game
{
public:
	TicTacToe(/*int difficult, string state*/ int sizeBoard);
	virtual void playerMove();
	virtual void computerMove();
	virtual void setBoard(int index);
	virtual void setState(string);
	virtual bool checkWinner();
	virtual bool checkValidation();
	/*void getWinner() { return winner; }*/
};

