#pragma once
#ifndef SLOT_H
#define SLOT_H
#include "EntityType.hpp"
#include <iostream>
using namespace std;

class Slot {
    int id;
    EntityType slotType;
    bool isAvailable;

    public:
        Slot(int, EntityType);
        EntityType getSlotType();
        int getSlotId();
        bool getAvailability();
        void setAvailability(bool);
};

#endif