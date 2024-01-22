#include "EntityFactory.hpp"
#include "Utility.hpp"

void printEntity(Entity*);

Entity* EntityFactory::createEntity(EntityType et, string col, int reg) {
    Entity* entity;
    switch (et) {
        case EntityType::CAR:
            entity = new Car(reg, col);
            break;
        case EntityType::BIKE:
            entity = new Bike(reg, col);
            break;
        case EntityType::TRUCK:
            entity = new Truck(reg, col);
            break;
        default:
            entity = NULL;
            break;
    }
    printEntity(entity);
    return entity;
}

void printEntity(Entity* entity) {
    cout<<"Entity details\n";
    cout<<"RegistrationID:"<<entity->getRegistration()<<", Entity Type:"<<Utility::getTypeString(entity->getType())
    <<", Color:"<<entity->getColor()<<"\n";
}
