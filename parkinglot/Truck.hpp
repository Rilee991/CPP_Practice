#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#include "Entity.hpp"

class Truck: public Entity {
    public:
        Truck(int, string);
        EntityType getType();
        string getColor();
        int getRegistration();
        string getTicket();
        void setTicket(string);
};

#endif