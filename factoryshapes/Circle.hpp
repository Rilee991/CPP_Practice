#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.hpp"

class Circle: public Shape {
    int radius;
    public:
        Circle(int radius);
        double getArea();
        double getPerimeter();
};

#endif