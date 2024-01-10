#pragma once 
#ifndef DICE_H
#define DICE_H
#include <iostream>
using namespace std;

class Dice {
    int numOfDices;
    public:
        Dice(int nod);
        int rollDice();
};

#endif
