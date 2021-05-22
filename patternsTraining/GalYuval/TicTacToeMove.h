#pragma once
#include "Moveable.h"
#include <iostream>
using namespace std;
class TicTacToeMove :
    public Moveable
{
public:
    TicTacToeMove();
public:
    void move(int** mat, int difficulty);
};

