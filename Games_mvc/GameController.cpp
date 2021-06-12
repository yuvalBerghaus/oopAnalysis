#include "GameController.h"

void GameController::play(int game_id , int sizeBoard)
{
	Game* game = _Model->getGame(game_id, sizeBoard); //factory

	while (!game->checkWinner()) {
		_View->printGameStatus(game);
		game->playerMove();
		if (!game->checkWinner())
			break;
		game->computerMove();
	}
	_View->printWinner(game->getWinner());
}
void GameController::getEnrolledGames() {

}