#pragma once
#ifndef SIMPLEBODY_H
#define SIMPLEBODY_H
#include <iostream>
#include "Body.hpp"
using namespace std;

class SimpleBody: public Body {
    public:
        void giveBodyName(string name);
        void putDoors(int d);
        string getBodyDetails();
};

#endif