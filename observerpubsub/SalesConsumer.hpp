#pragma once
#ifndef SALESCONSUMER_H
#define SALESCONSUMER_H

#include "Consumer.hpp"

class SalesConsumer: public Consumer {
    public:
        SalesConsumer(int id);
        int getId();
        void update();
};

#endif