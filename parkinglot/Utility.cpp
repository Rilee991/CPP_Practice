#include "Utility.hpp"

string Utility::getTypeString(EntityType type) {
    string typeString;

    switch (type) {
        case EntityType::CAR:
            typeString = "CAR";
            break;
        case EntityType::BIKE:
            typeString = "BIKE";
            break;
        case EntityType::TRUCK:
            typeString = "TRUCK";
            break;
        default:
            typeString = "INVALID_TYPE";
            break;
    }

    return typeString;
}