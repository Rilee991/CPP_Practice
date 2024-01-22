#pragma once
#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include "Car.hpp"
#include "Bike.hpp"
#include "Truck.hpp"

class EntityFactory {
    public:
        static Entity* createEntity(EntityType, string, int);
};

#endif