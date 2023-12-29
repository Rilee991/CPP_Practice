#pragma once
#ifndef SIMPLECARFACTORY_H
#define SIMPLECARFACTORY_H
#include <iostream>
#include "CarFactory.hpp"
using namespace std;

class SimpleCarFactory: public CarFactory {
    public:
        Tire* createTire();
        Body* createBody();
        Car* buildCar();
        CarFactory* getCarFactory();
};

#endif