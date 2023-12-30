#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle {
    protected:
        int tyres;
        string engine;
        string vehicleType;
    public:
        virtual void buildEngine(string engine) = 0;
        virtual void buildTyres(int tyres) = 0;
        virtual void displyVehicle() = 0;
};

#endif
