#include<iostream>
#include "vehicle_factory.hpp"
using namespace std;

int main() {
    string vtype;
    cin>>vtype;

    Vehicle *vehicle = VehicleFactory::getVehicle(vtype);
    vehicle->createVehicle();

    return 0;
}