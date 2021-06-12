#include "GameController.h"

void GameController::play(int game_id)
{
	Game* game = _Model->getGame(game_id); //factory

	while (!game->checkWinner()) {
		_View->printGameStatus(game);
		game->playerMove();
		if (!game->checkWinner())
			break;
		game->computerMove();
	}
	_View->printWinner(game->getWinner());
}
