#include <iostream>
#include "VehicleFactory.hpp"
#include "Car.hpp"
#include "Bike.hpp"
using namespace std;

Vehicle* VehicleFactory::buildVehicle(int type) {
    Vehicle *vehicle;
    switch(type) {
        case 1: vehicle = new Car();
            break;
        case 2: vehicle = new Bike();
            break;
        default: vehicle = new Car();
            break;
    }

    return vehicle;
}
