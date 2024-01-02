#pragma once
#ifndef DICE_H
#define DICE_H

class Dice {
    int size;
    int numOfDices;

    public:
        Dice(int s, int n);
        int rollDice();
};

#endif