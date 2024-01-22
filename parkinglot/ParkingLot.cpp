#include "ParkingLot.hpp"
#include "Utility.hpp"

ParkingLot* ParkingLot::instance = NULL;

ParkingLot::ParkingLot(string id, int numFloors, int numSlots) {
    this->id = id;
    numOfFloors = numFloors;
    floors.resize(numOfFloors);
    for(int id=0;id<numOfFloors;id++) {
        floors[id] = new Floor(id,numSlots);
    }
    cout<<"Parking lot created\n";
}

ParkingLot* ParkingLot::createParkingLot(string id, int numFloors, int numSlots) {
    if(!instance) {
        instance = new ParkingLot(id, numFloors, numSlots);
    }

    return instance;
}

int ParkingLot::getAvailableSlotsForVehicleTypeByFloorId(int fId, EntityType eType) {
    for(Floor* floor: floors) {
        if(floor->getFloorId() == fId) return floor->getAvailableSlotsByEntityType(eType);
    }

    return -1;
}

int ParkingLot::getTotalSlotsByFloor(int fId) {
    for(Floor* floor: floors) {
        if(floor->getFloorId() == fId) return floor->getTotalSlots();
    }

    return -1;
}

int ParkingLot::getUnavailableSlotsForVehicleTypeByFloorId(int fId, EntityType eType) {
    for(Floor* floor: floors) {
        if(floor->getFloorId() == fId) return floor->getUnavailableSlotsByEntityType(eType);
    }

    return -1;
}

void ParkingLot::printParkingLot() {
    cout<<"Parking Lot Status\n";
    for(Floor* floor: floors) {
        cout<<"Displaying Floor:"<<floor->getFloorId()<<"\n";
        for(Slot* slot: floor->getSlots()) {
            cout<<"Slot ID:"<<slot->getSlotId()<<", Slot Type:"<<Utility::getTypeString(slot->getSlotType());
            cout<<", Is Available:"<<slot->getAvailability();
            cout<<"\n";
        }
    }
}

pair<Floor*,Slot*> ParkingLot::findSlot(Entity* vehicle) {
    for(Floor* floor: floors) {
        for(Slot* slot: floor->getSlots()) {
            if(slot->getAvailability() && slot->getSlotType() == vehicle->getType())
                return {floor, slot};
        }
    }

    return {NULL,NULL};
}

Ticket* ParkingLot::issueTicket(Entity* vehicle, Floor* floor, Slot* slot) {
    int cost = vehicle->getType() == EntityType::TRUCK ? 100 : (vehicle->getType() == EntityType::CAR ? 70 : 50);
    string ticketId = id + "_" + to_string(floor->getFloorId()) + "_" + to_string(slot->getSlotId());
    Ticket* ticket = new Ticket(ticketId, cost, slot, floor, 2, vehicle);
    // string id, int cost, int slotId, int floorId, int expTime, Entity* vehicle
    tickets.push_back(ticket);
    return ticket;
}

string ParkingLot::parkVehicle(Entity* vehicle) {
    // findSlot
    pair<Floor*,Slot*> slots = findSlot(vehicle);
    Floor* floor = slots.first;
    Slot* slot = slots.second;

    if(floor == NULL) {
        cout<<"Cannot park vehicle. All slots are occupied\n";
        return "Cannot park vehicle. All slots are occupied";
    }
    
    // issueTicket
    Ticket* ticket = issueTicket(vehicle, floor, slot);

    // return ticket
    cout<<"Vehicle Parked with ticked:"<<ticket->getId()<<"\n";
    return ticket->getId();
}

string ParkingLot::releaseSlot(string ticketId) {
    string msg = "No ticket is present with this id:" + ticketId;
    int id = 0;
    for(Ticket* ticket: tickets) {
        if(ticket->getId() == ticketId) {
            cout<<"Ticket released with ticket id: " +ticketId<<"\n";
            tickets.erase(tickets.begin()+id);
            delete ticket;
            break;
        }
        id++;
    }

    return msg;
}

