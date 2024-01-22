#include "Ticket.hpp"

    // int id;
    // int cost;
    // int slotId;
    // int floorId;
    // int expirationTime;
    // Entity* vehicle;

Ticket::Ticket(string id, int cost, Slot* slot, Floor* floor, int expTime, Entity* vehicle) {
    this->id = id;
    this->cost = cost;
    this->slot = slot;
    this->floor = floor;
    this->expirationTime = expirationTime;
    this->vehicle = vehicle;
    slot->setAvailability(false);
}

Ticket::~Ticket() {
    cout<<"Availability is reset\n";
    slot->setAvailability(true);
}

string Ticket::getId() {
    return id;
}

int Ticket::getCost() {
    return cost;
}

Slot* Ticket::getSlot() {
    return slot;
}

Floor* Ticket::getFloor() {
    return floor;
}

int Ticket::getExpirationTime() {
    return expirationTime;
}

Entity* Ticket::getVehicle() {
    return vehicle;
}
