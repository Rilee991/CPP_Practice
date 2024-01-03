#pragma once
#ifndef DICE_H
#define DICE_H
#include <iostream>

class Dice {
    int maxVal;
    int count;
    public:
        Dice(int mv, int ctr);
        int rollDice();
};

#endif