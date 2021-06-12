#include <iostream>
using namespace std;
//this class is abstract

class Game {
public:
	int getBoard(int game_id);
	string getState(int game_id);

	virtual void playerMove() = 0;
	virtual void computerMove() = 0;
	bool checkValidation();
	bool checkWinner(); //if there winner return 1
	virtual void setBoard(int index) = 0;
	virtual void setState(string) = 0;
	virtual int getWinner();

public:
	int _board;
	int winner;
	string _state;
};