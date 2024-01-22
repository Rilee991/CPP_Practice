#pragma once
#ifndef FLOOR_H
#define FLOOR_H
#include "Slot.hpp"
#include <vector>
using namespace std;

class Floor {
    int id;
    int numOfSlots;
    vector<Slot*> slots;

    public:
        Floor(int, int);
        int getFloorId();
        vector<Slot*> getSlots();
        int getAvailableSlotsByEntityType(EntityType);
        int getTotalSlots();
        int getUnavailableSlotsByEntityType(EntityType);
};

#endif