#pragma once
#include "Game.h"
class TicTacToe :
    public Game
{
public:
    TicTacToe(Moveable* type, int difficulty, int sizeBoard);
public:
    void moveHim();
};

