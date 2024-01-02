#pragma once
#ifndef ORDERCONSUMER_H
#define ORDERCONSUMER_H
#include "Consumer.hpp"

class OrderConsumer: public Consumer {
    public:
        OrderConsumer(int id);
        void processData();
        int getId();
};

#endif
