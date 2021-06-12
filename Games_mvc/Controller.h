#pragma once
//this class is interface
#include <iostream>
using namespace std;

class Controller {
public:
	Controller();
	virtual ~Controller() = 0;
	virtual void play(Game&) = 0;
	virtual void displayEnrolledGames() = 0;
	virtual void addGame() = 0;
	virtual void removeGame() = 0;
};