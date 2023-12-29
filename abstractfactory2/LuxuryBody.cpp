#include <iostream>
#include "LuxuryBody.hpp"
using namespace std;

void LuxuryBody::giveBodyName(string name) {
    this->name = name;
    this->type = "Luxury Body";
}

void LuxuryBody::putDoors(int d) {
    this->doors = d;
}

string LuxuryBody::getBodyDetails() {
    string str = "Body name:" + name + ", doors:" + to_string(doors) + ", type: " + type;
    return str;
}
