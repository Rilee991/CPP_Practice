#pragma once
#ifndef CONSUMER_H
#define CONSUMER_H

#include <iostream>
using namespace std;

class Consumer {
    protected:
        int id;
    public:
        int getId();
        virtual void update() = 0;
};

#endif