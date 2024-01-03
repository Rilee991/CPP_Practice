#include "Snake.hpp"
#include <iostream>

Snake::Snake(int start, int end) {
    this->start = start;
    this->end = end;
}

Snake* Snake::createSnake(int start, int end) {
    if(start <= end) {
        std::cout<<"Invalid snake positions\n";
        return NULL;
    }

    return new Snake(start, end);
}
