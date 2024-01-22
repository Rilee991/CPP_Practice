#pragma once
#ifndef BIKE_H
#define BIKE_H
#include "Entity.hpp"

class Bike: public Entity {
    public:
        Bike(int, string);
        EntityType getType();
        string getColor();
        int getRegistration();
};

#endif