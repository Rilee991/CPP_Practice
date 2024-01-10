#include "Dice.hpp"
#include <random>

Dice::Dice(int nod) {
    numOfDices = nod;
}

int Dice::rollDice() {
    int startVal = numOfDices;
    int endVal = 6*numOfDices;

    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> func(startVal, endVal);

    return func(eng);    
}
