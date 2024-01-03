#include <iostream>
#include <vector>
#include "Board.hpp"

Board::Board(int bSize, Dice* dice, std::vector<Entity*> entities) {
    this->boardSize = bSize;
    this->dice = dice;
    for(auto entity: entities) {
        if(entity->getEnd() > entity->getStart()) {
            this->ladders.push_back(entity);
        } else {
            this->snakes.push_back(entity);
        }
    }
}
