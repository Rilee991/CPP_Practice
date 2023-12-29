#pragma once
#ifndef LUXURYBODY_H
#define LUXURYBODY_H
#include <iostream>
#include "Body.hpp"
using namespace std;

class LuxuryBody: public Body {
    public:
        void giveBodyName(string name);
        void putDoors(int d);
        string getBodyDetails();
};

#endif