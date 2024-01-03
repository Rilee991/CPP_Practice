#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "Dice.hpp"

class Board {
    int boardSize;
    Dice* dice;
    std::vector<Entity*> ladders;
    std::vector<Entity*> snakes;

    public:
        Board(int bSize, Dice* dice, std::vector<Entity*> entities);
};

#endif