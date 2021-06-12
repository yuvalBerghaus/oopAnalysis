#include <iostream>
using namespace std;
//this class is abstract

class Game {
public:
	Game(int);
public:
	int getBoard(int game_id);
	string getState(int game_id);
	virtual void playerMove() = 0;
	virtual void computerMove() = 0;
	virtual bool checkValidation() = 0;
	virtual bool checkWinner() = 0; //if there winner return 1
	virtual void setBoard(int index) = 0;
	virtual void setState(string) = 0;
	virtual int getWinner();

protected:
	int** _board;
	int winner;
	string _state;
	int _boardSize;
};