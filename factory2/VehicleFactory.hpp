#pragma once
#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H
#include "Vehicle.hpp"
#include <iostream>

using namespace std;

class VehicleFactory {
    public:
        Vehicle* buildVehicle(int type);
};

#endif