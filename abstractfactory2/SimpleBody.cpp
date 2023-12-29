#include <iostream>
#include "SimpleBody.hpp"
using namespace std;

void SimpleBody::giveBodyName(string name) {
    this->name = name;
    this->type = "Simple Body";
}

void SimpleBody::putDoors(int d) {
    this->doors = d;
}

string SimpleBody::getBodyDetails() {
    string str = "Body name:" + name + ", doors:" + to_string(doors) + ", type: " + type;
    return str;
}

