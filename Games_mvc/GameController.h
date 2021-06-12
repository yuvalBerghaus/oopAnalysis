#pragma once
#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Game.h"
#include <iostream>
#include <iterator>
#include <map>

class GameController : Controller
{
public:
	GameController(Model, View);
	~GameController();
	void play(int game_id,int sizeBoard);
	void displayEnrolledGames();
	void addGame();
	void removeGame();
	std::map<int, Game&> getEnrolledGames();
private:
	View* _View;
	Model* _Model;
};

