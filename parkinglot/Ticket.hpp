#pragma once
#ifndef TICKET_H
#define TICKET_H
#include "Entity.hpp"
#include "Slot.hpp"
#include "Floor.hpp"
#include <iostream>
using namespace std;

class Ticket {
    string id;
    int cost;
    Slot* slot;
    Floor* floor;
    int expirationTime;
    Entity* vehicle;

    public:
        Ticket(string, int, Slot*, Floor*, int, Entity*);
        ~Ticket();
        string getId();
        int getCost();
        Slot* getSlot();
        Floor* getFloor();
        int getExpirationTime();
        Entity* getVehicle();
};

#endif