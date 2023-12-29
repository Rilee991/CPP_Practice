#include <iostream>
#include "SimpleCarFactory.hpp"
#include "SimpleTire.hpp"
#include "SimpleBody.hpp"
#include "Car.hpp"
using namespace std;

Tire* SimpleCarFactory::createTire() {
    SimpleTire *st = new SimpleTire();
    st->giveTireName("Hyundai Simple Tire");
    st->putPressure(10);

    return st;
}

Body* SimpleCarFactory::createBody() {
    SimpleBody *sb = new SimpleBody();
    sb->giveBodyName("Hyundai Simple Body");
    sb->putDoors(4);

    return sb;
}

Car* SimpleCarFactory::buildCar() {
    Car* car = new Car("Simple Car");
    car->setBody(createBody());
    car->setTire(createTire());

    return car;
}

CarFactory* SimpleCarFactory::getCarFactory() {
    return new SimpleCarFactory();
}
