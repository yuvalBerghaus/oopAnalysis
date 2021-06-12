#include <iostream>
#include <iterator>
#include <map>
//this class is interface
class View {
public:
	virtual void printGameStatus(Game*) = 0;
	virtual void displayEnrolledGames(std::map<int, Game&>) = 0;
	virtual void printWinner(int winner) = 0;
};