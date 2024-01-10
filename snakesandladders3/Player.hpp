#pragma once 
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <queue>
using namespace std;

class Player {
    string name;
    int moves;
    int position;
    queue<int> lastThreeDices;
    public:
        Player(string name);
        int getMoves();
        int getPosition();
        void setMoves(int m);
        void setPosition(int p);
        queue<int> getLastThreeDices();
        void setLastThreeDices(queue<int> q);
        string getName();
};

#endif
