#include "View.h"
#include "Game.h"

class GUIview
{
	GUIview();
	void printGameStatus(Game*);
	void displayEnrolledGames(std::map<int, Game&>);
	void printWinner(int winner);
};

