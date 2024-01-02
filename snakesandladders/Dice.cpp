#include <iostream>
#include <random>
#include "Dice.hpp"
using namespace std;

Dice::Dice(int s, int n) {
    size = s;
    numOfDices = n;
}

int Dice::rollDice() {
    int maxNum = size * numOfDices;
    int minNum = 1;

    random_device rd;
    mt19937 eng(rd());

    uniform_int_distribution<> distr(minNum, maxNum);
    
    return distr(eng);
}
