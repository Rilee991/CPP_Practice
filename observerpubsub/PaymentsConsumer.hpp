#pragma once
#ifndef PAYMENTSCONSUMER_H
#define PAYMENTSCONSUMER_H

#include "Consumer.hpp"

class PaymentsConsumer: public Consumer {
    public:
        PaymentsConsumer(int id);
        int getId();
        void update();
};

#endif