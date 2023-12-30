#include <iostream>
#include "Car.hpp"
using namespace std;

void Car::buildEngine(string e) {
    this->engine = e;
    this->vehicleType = "Car";
}

void Car::buildTyres(int t) {
    this->tyres = t;
}

void Car::displyVehicle() {
    cout<<"Car info: Engine:"<<engine<<", tyres:"<<tyres<<", type:"<<vehicleType<<endl;
}