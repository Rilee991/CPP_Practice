#include <iostream>
#include "Entity.hpp"
using namespace std;

Entity::Entity(int s, int e) {
    start = s;
    end = e;
    isSnake = s > e;
}

bool Entity::getIsSnake() {
    return isSnake;
}

bool Entity::getIsLadder() {
    return isLadder;
}

int Entity::getEnd() {
    return end;
}

int Entity::getStart() {
    return start;
}
