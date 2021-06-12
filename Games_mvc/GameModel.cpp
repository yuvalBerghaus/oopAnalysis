#include "GameModel.h"

Game* GameModel::getGame(int game_id, int sizeBoard)
{
	if (game_id == 1) {
		return new TicTacToe_Normal(sizeBoard);
	}
	else if (game_id == 2)
		return new TicTacToe_Hard(sizeBoard);
}