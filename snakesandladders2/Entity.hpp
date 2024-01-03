#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>

class Entity {
    protected:
        int start;
        int end;

    public:
        int getStart();
        int getEnd();
};

#endif