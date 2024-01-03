#include "Ladder.hpp"
#include <iostream>

Ladder::Ladder(int start, int end) {
    this->start = start;
    this->end = end;
}

Ladder* Ladder::createLadder(int start, int end) {
    if(start <= end) {
        std::cout<<"Invalid ladder positions\n";
        return NULL;
    }

    return new Ladder(start, end);
}