#include "Car.hpp"

Car::Car(int reg, string col) {
    this->type = EntityType::CAR;
    this->color = col;
    this->registration = reg;
}

EntityType Car::getType() {
    return type;
}

string Car::getColor() {
    return color;
}

int Car::getRegistration() {
    return registration;
}
