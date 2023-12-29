#include <iostream>
#include "LuxuryCarFactory.hpp"
#include "LuxuryTire.hpp"
#include "LuxuryBody.hpp"
#include "Car.hpp"
using namespace std;

Tire* LuxuryCarFactory::createTire() {
    LuxuryTire *st = new LuxuryTire();
    st->giveTireName("Hyundai Luxury Tire");
    st->putPressure(10);

    return st;
}

Body* LuxuryCarFactory::createBody() {
    LuxuryBody *sb = new LuxuryBody();
    sb->giveBodyName("Hyundai Luxury Body");
    sb->putDoors(4);

    return sb;
}

Car* LuxuryCarFactory::buildCar() {
    Car* car = new Car("Luxury Car");
    car->setBody(createBody());
    car->setTire(createTire());

    return car;
}

CarFactory* LuxuryCarFactory::getCarFactory() {
    return new LuxuryCarFactory();
}
