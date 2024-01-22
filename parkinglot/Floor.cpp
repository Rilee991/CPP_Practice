#include "Floor.hpp"

Floor::Floor(int id, int nos) {
    this->id = id;
    numOfSlots = nos;
    slots.resize(numOfSlots);
    EntityType entityType = EntityType::CAR;
    
    for(int id=0;id<numOfSlots;id++) {
        if(id == 0) entityType = EntityType::TRUCK;
        else if(id <= 2) entityType = EntityType::BIKE;
        else entityType = EntityType::CAR;
        slots[id] = new Slot(id,entityType);
    }
}

int Floor::getFloorId() {
    return id;
}

vector<Slot*> Floor::getSlots() {
    return slots;
}

int Floor::getAvailableSlotsByEntityType(EntityType eType) {
    int availableSlots = 0;
    for(Slot* slot: slots) {
        if(slot->getAvailability() && slot->getSlotType() == eType)
            availableSlots++; 
    }

    return availableSlots;
}

int Floor::getTotalSlots() {
    return numOfSlots;
}

int Floor::getUnavailableSlotsByEntityType(EntityType eType) {
    return getTotalSlots()-getAvailableSlotsByEntityType(eType);
}

