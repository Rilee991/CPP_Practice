#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Player.hpp"
#include "Entity.hpp"
#include "Dice.hpp"
#include <vector>
using namespace std;

class GameBoard {
    int size;
    vector<Player*> players;
    Dice* dice;
    vector<Entity*> entities;

    public:
        GameBoard(int s, vector<Player*> p, Dice* d, vector<Entity*> e);
        void startGame();
};

#endif