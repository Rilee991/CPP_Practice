#include "Truck.hpp"

Truck::Truck(int reg, string col) {
    this->type = EntityType::TRUCK;
    this->color = col;
    this->registration = reg;
}

EntityType Truck::getType() {
    return type;
}

string Truck::getColor() {
    return color;
}

int Truck::getRegistration() {
    return registration;
}
