#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include "Entity.hpp"

class Snake: public Entity {
    public:
        Snake(int start, int end);
        static Snake* createSnake(int start, int end);
};

#endif