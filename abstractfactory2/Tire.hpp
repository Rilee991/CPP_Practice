#pragma once
#ifndef TIRE_H
#define TIRE_H
#include <iostream>
using namespace std;

class Tire {
    protected:
        string name;
        int pressure;
        string type;
    public:
        virtual void giveTireName(string name) = 0;
        virtual void putPressure(int p) = 0;
        virtual string getTireDetails() = 0;
};

#endif