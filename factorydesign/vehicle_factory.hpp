#ifndef vehicle_factory
#define vehicle_factory

#include<iostream>
#include "bike.hpp"
#include "car.hpp"
using namespace std;

class VehicleFactory {
    public:
        static Vehicle *getVehicle(string vType); //this is made static because we don't need to access the fn with an obj, we can directly access it using class
};

#endif