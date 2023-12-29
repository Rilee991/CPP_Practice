#include <iostream>
#include "LuxuryTire.hpp"
using namespace std;

void LuxuryTire::giveTireName(string name) {
    this->name = name;
    this->type = "Luxury";
}

void LuxuryTire::putPressure(int p) {
    this->pressure = p;
}

string LuxuryTire::getTireDetails() {
    string str = "Tire name:" + name + ", pressure:" + to_string(pressure) + ", type: " + type;
    return str;
}
