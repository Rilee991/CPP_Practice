#pragma once
#ifndef LUXURYTIRE_H
#define LUXURYTIRE_H
#include <iostream>
#include "Tire.hpp"
using namespace std;

class LuxuryTire: public Tire {
    public:
        void giveTireName(string name);
        void putPressure(int p);
        string getTireDetails();

};

#endif