#pragma once
#ifndef SIMPLETIRE_H
#define SIMPLETIRE_H
#include <iostream>
#include "Tire.hpp"
using namespace std;

class SimpleTire: public Tire {
    public:
        void giveTireName(string name);
        void putPressure(int p);
        string getTireDetails();
};

#endif