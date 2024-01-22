#pragma once
#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "Floor.hpp"
#include "Entity.hpp"
#include "Ticket.hpp"
#include <vector>
using namespace std;

class ParkingLot {
    string id;
    int numOfFloors;
    vector<Floor*> floors;
    vector<Ticket*> tickets;
    static ParkingLot* instance;

    public:
        ParkingLot(string, int, int);
        static ParkingLot* createParkingLot(string id, int numFloors, int numSlots);
        void printParkingLot();
        int getAvailableSlotsForVehicleTypeByFloorId(int, EntityType);
        int getTotalSlotsByFloor(int);
        int getUnavailableSlotsForVehicleTypeByFloorId(int, EntityType);
        string parkVehicle(Entity*);
        Ticket* issueTicket(Entity*, Floor*, Slot*);
        pair<Floor*,Slot*> findSlot(Entity*);
        string releaseSlot(string);
};

#endif