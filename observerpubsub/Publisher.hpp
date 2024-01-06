#pragma once
#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <list>
#include "Consumer.hpp"

class Publisher {
    list<Consumer*> consumers;
    public:
        void addConsumers(Consumer* consumer);
        void removeConsumers(Consumer* consumer);
        void updateConsumers();
};

#endif