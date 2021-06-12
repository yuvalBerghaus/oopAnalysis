#include "GameModel.h"

Game* GameModel::getGame(int game_id)
{
	if (game_id == 1)
		return new TicTacToe_Normal();
	if (game_id == 2)
		return new TicTacToe_Hard();
}
