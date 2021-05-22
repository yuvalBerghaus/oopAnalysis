#include "TicTacToe.h"
#include "TicTacToeMove.h"
using namespace std;
int main() {
	Game* tic = new TicTacToe(new TicTacToeMove() , 2 , 3);
	tic->moveHim();
	return 0;
}