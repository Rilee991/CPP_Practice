#pragma once 
#ifndef BOARD_H
#define BOARD_H
#include "Entity.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include <list>

class Board {
    int boardSize;
    list<Player*> players;
    list<Entity*> ladders;
    list<Entity*> snakes;
    Dice* dice;

    public:
        Board(int boardSize, list<Player*> players, list<Entity*> ladders, list<Entity*> snakes, Dice* dice);
        void startGame();
};

#endif
