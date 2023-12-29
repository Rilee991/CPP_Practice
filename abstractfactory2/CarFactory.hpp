#pragma once
#ifndef CARFACTORY_H
#define CARFACTORY_H
#include <iostream>
#include "Car.hpp"
using namespace std;

class CarFactory {
    Car* car;
    public:
        virtual Tire* createTire() = 0;
        virtual Body* createBody() = 0;
        virtual Car* buildCar() = 0;
        virtual CarFactory* getCarFactory() = 0;
};

#endif