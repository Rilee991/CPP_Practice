#include "Bike.hpp"

Bike::Bike(int reg, string col) {
    this->type = EntityType::BIKE;
    this->color = col;
    this->registration = reg;
}

EntityType Bike::getType() {
    return type;
}

string Bike::getColor() {
    return color;
}

int Bike::getRegistration() {
    return registration;
}