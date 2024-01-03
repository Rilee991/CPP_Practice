#include "Dice.hpp"
#include <iostream>
#include <random>

Dice::Dice(int mv, int ctr) {
    this->maxVal = mv;
    this->count = ctr;
}

int Dice::rollDice() {
    int startVal = 1;
    int endVal = count * maxVal;

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> func(startVal, endVal);

    return func(eng);
}
