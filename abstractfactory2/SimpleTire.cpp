#include <iostream>
#include "SimpleTire.hpp"
using namespace std;

void SimpleTire::giveTireName(string name) {
    this->name = name;
    this->type = "Simple";
}

void SimpleTire::putPressure(int p) {
    this->pressure = p;
}

string SimpleTire::getTireDetails() {
    string str = "Tire name:" + name + ", pressure:" + to_string(pressure) + ", type: " + type;
    return str;
}
