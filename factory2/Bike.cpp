#include <iostream>
#include "Bike.hpp"
using namespace std;

void Bike::buildEngine(string e) {
    this->engine = e;
    this->vehicleType = "Bike";
}

void Bike::buildTyres(int t) {
    this->tyres = t;
}

void Bike::displyVehicle() {
    cout<<"Bike info: Engine:"<<engine<<", tyres:"<<tyres<<", type:"<<vehicleType<<endl;
}
