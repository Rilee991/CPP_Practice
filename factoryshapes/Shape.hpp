#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape {
    protected:
        string type;
    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
};

#endif