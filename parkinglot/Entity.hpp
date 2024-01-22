#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "EntityType.hpp"
#include <unordered_map>
#include <iostream>
using namespace std;

class Entity {
    protected:
        EntityType type;
        string color;
        int registration;
    public:
        virtual EntityType getType() = 0;
        virtual string getColor() = 0;
        virtual int getRegistration() = 0;
};

#endif