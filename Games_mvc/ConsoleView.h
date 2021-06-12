#include "View.h"
#include "Game.h"

class ConsoleView : public View
{
	ConsoleView();
	void printGameStatus(Game&);
	void displayEnrolledGames(std::map<int, Game&>);
	void printWinner(int winner);
};

