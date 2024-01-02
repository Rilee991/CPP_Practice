#pragma once
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    int start;
    int end;
    bool isSnake;
    bool isLadder;

    public:
        Entity(int s, int e);
        bool getIsSnake();
        bool getIsLadder();
        int getEnd();
        int getStart();
};

#endif