#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player {
    std::string name;
    int numOfMoves;
    int position;

    public:
        Player(std::string name);
        int getNumOfMoves();
        void setNumOfMoves(int moves);
        int getPosition();
        std::string getName();
        void setPosition(int position);
};

#endif