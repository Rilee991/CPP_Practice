#pragma once
#ifndef CAR_H
#define CAR_H
#include "Entity.hpp"

class Car: public Entity {
    public:
        Car(int, string);
        EntityType getType();
        string getColor();
        int getRegistration();
};

#endif