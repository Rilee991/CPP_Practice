#pragma once
#ifndef BODY_H
#define BODY_H
#include <iostream>
using namespace std;

class Body {
    protected:
        string name;
        int doors;
        string type;
    public:
        virtual void giveBodyName(string name) = 0;
        virtual void putDoors(int d) = 0;
        virtual string getBodyDetails() = 0;
};

#endif