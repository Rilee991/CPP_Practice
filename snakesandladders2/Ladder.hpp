#pragma once
#ifndef LADDER_H
#define LADDER_H
#include <iostream>
#include "Entity.hpp"

class Ladder: public Entity {
    public:
        Ladder(int start, int end);
        Ladder* createLadder(int start, int end);
};

#endif