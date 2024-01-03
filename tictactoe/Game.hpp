#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include <vector>
using namespace std;

class Game {
    Board board;
    vector<Player*> players;

    public:
        Game(int bSize, vector<Player*> p);
        void startGame();
};


#endif