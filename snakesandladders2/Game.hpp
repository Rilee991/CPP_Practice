#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"

class Game {
    Board* board;
    int bSize;
    std::vector<Player*> players;
    Dice* dice;
    std::vector<Entity*> entities;

    public:
        Game(int bSize, std::vector<Player*> players, Dice* dice, std::vector<Entity*> entities);
        void startGame();
};

#endif