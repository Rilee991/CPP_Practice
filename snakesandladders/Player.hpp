#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
    string name;
    int numOfMoves;
    int position;

    public:
        Player(string n);
        int getNumOfMoves();
        void setNumOfMoves(int numOfMoves);
        string getName();
        void setName(string name);
        int getPosition();
        void setPosition(int position);
};

#endif