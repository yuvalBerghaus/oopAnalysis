#include "Model.h"
#include "Game.h"
#include "TicTacToe_Normal.h"
#include "TicTacToe_Hard.h"
#include <iostream>
using namespace std;
class GameModel : public Model
{
public:
	GameModel();
	void addGame();
	std::map<int, Game&> getEnrolledGames();
	Game* getGame(int game_id , int sizeBoard);
	int getBoard(int game_id);
	string getState(int game_id);
private:
	std::map<int, Game*> _Games;
};

