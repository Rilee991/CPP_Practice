#pragma once
#ifndef TOPIC_H
#define TOPIC_H
#include "Consumer.hpp"
#include <list>
using namespace std;

class Topic {
    list<Consumer*> consumers;
    public:
        void subscribe(Consumer* c);
        void unsubscribe(Consumer* c);
        void displayConsumers();
        void notifyAll();
        int getId();
};

#endif
