#pragma once
#ifndef LUXURYCARFACTORY_H
#define LUXURYCARFACTORY_H
#include <iostream>
#include "CarFactory.hpp"
using namespace std;

class LuxuryCarFactory: public CarFactory {
    public:
        Tire* createTire();
        Body* createBody();
        Car* buildCar();
        CarFactory* getCarFactory();
};

#endif