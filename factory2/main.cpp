#include <iostream>
#include "VehicleFactory.hpp"
// #include "Vehicle.hpp"
using namespace std;

int main() {
    VehicleFactory *factory;
    Vehicle* vehicle = factory->buildVehicle(1);

    vehicle->buildEngine("Auto Engine");
    vehicle->buildTyres(3);
    vehicle->displyVehicle();

    vehicle = factory->buildVehicle(2);

    vehicle->buildEngine("Cycle Engine");
    vehicle->buildTyres(2);
    vehicle->displyVehicle();

    vehicle = factory->buildVehicle(5);

    vehicle->buildEngine("Cycle Engine");
    vehicle->buildTyres(2);
    vehicle->displyVehicle();
}