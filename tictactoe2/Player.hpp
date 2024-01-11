#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Symbol.hpp"
using namespace std;

class Player {
    string name;
    int moves;
    Symbol symbol;

    public:
        Player(string, Symbol);
        string getName();
        int getMoves();
        void setMoves(int);
        Symbol getSymbol();
};

#endif