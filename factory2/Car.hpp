#pragma once
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

class Car: public Vehicle {
    public:
        void buildEngine(string e);
        void buildTyres(int t);
        void displyVehicle();
};

#endif