#include <iostream>
#include "CarFactory.hpp"
#include "SimpleCarFactory.hpp"
#include "LuxuryCarFactory.hpp"
using namespace std;

int main() {
    int type;
    cin>>type;
    CarFactory* factory;

    if(type == 1) {
        factory = new SimpleCarFactory();
    } else {
        factory = new LuxuryCarFactory();
    }

    Car* car = factory->buildCar();
    car->displayCar();

    return 0;
}