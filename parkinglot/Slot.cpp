#include "Slot.hpp"

Slot::Slot(int sId, EntityType sType) {
    id = sId;
    slotType = sType;
    isAvailable = true;
}

EntityType Slot::getSlotType() {
    return slotType;
}

int Slot::getSlotId() {
    return id;
}

bool Slot::getAvailability() {
    return isAvailable;
}

void Slot::setAvailability(bool availability) {
    isAvailable = availability;
}
