#include "ParkingLot.hpp"
#include "EntityFactory.hpp"
#include <vector>
using namespace std;

int main() {
    int numOfFloors = 3;
    int numOfSlotsPerFloor = 5;
    Entity* b1 = EntityFactory::createEntity(EntityType::BIKE, "Red", 1);
    Entity* b2 = EntityFactory::createEntity(EntityType::BIKE, "Green", 2);
    Entity* b3 = EntityFactory::createEntity(EntityType::BIKE, "Blue", 3);
    Entity* b4 = EntityFactory::createEntity(EntityType::BIKE, "White", 4);


    Entity* c1 = EntityFactory::createEntity(EntityType::CAR, "Red", 1);
    Entity* c2 = EntityFactory::createEntity(EntityType::CAR, "Green", 2);
    Entity* c3 = EntityFactory::createEntity(EntityType::CAR, "Blue", 3);
    Entity* c4 = EntityFactory::createEntity(EntityType::CAR, "White", 4);


    Entity* t1 = EntityFactory::createEntity(EntityType::TRUCK, "Red", 1);
    Entity* t2 = EntityFactory::createEntity(EntityType::TRUCK, "Green", 2);
    Entity* t3 = EntityFactory::createEntity(EntityType::TRUCK, "Blue", 3);
    Entity* t4 = EntityFactory::createEntity(EntityType::TRUCK, "White", 4);

    ParkingLot* lot = ParkingLot::createParkingLot("PR1234", numOfFloors, numOfSlotsPerFloor); /// new ParkingLot("PR1234", numOfFloors, numOfSlotsPerFloor);
    ParkingLot* lot2 = ParkingLot::createParkingLot("PR1234", numOfFloors, numOfSlotsPerFloor); /// new ParkingLot("PR1234", numOfFloors, numOfSlotsPerFloor);
    lot->printParkingLot();

    string tk1 = lot->parkVehicle(t1);
    // lot->printParkingLot();
    string tk2 = lot->parkVehicle(t2);
    cout<<"Available slots:"<<lot->getAvailableSlotsForVehicleTypeByFloorId(0, EntityType::TRUCK)<<"\n";
    cout<<"Total slots:"<<lot->getTotalSlotsByFloor(0)<<"\n";
    cout<<"Unavailable slots:"<<lot->getUnavailableSlotsForVehicleTypeByFloorId(0, EntityType::TRUCK)<<"\n";
    // lot->printParkingLot();
    string tk3 = lot->parkVehicle(t3);
    // lot->printParkingLot();
    string tk4 = lot->parkVehicle(t4);
    lot->printParkingLot();

    cout<<"Releasing....\n";
    tk4 = lot->releaseSlot(tk3);
    lot->printParkingLot();
    tk4 = lot->parkVehicle(t4);
    lot->printParkingLot();
    cout<<"Lot2 Displaying:\n";
    lot2->printParkingLot();
}
