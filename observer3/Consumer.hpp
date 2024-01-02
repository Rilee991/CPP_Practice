#pragma once
#ifndef CONSUMER_H
#define CONSUMER_H

class Consumer {
    protected:
        int id;
    public:
        virtual void processData() = 0;
        virtual int getId() = 0;
};

#endif
