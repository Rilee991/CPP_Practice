#pragma once
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Tire.hpp"
#include "Body.hpp"
using namespace std;

class Car {
    protected:
        Tire* tire;
        Body* body;
        string name;
    public:
        Car(string n);
        void setTire(Tire* t);
        void setBody(Body* b);
        void displayCar();
};

#endif