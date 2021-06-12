#include <iostream>
#include <map>
using namespace std;

//this class is interface
class Model {
public:
	virtual void addGame() = 0;
	virtual Game* getGame(int game_id, int sizeBoard) = 0;
	virtual int getBoard(int game_id) = 0;
	virtual string getState(int game_id) = 0;
	virtual std::map<int, Game&> getEnrolledGames() = 0;
};
