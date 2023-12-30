#pragma once
#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

class Bike: public Vehicle {
    public:
        void buildEngine(string e);
        void buildTyres(int t);
        void displyVehicle();
};

#endif