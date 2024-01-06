#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.hpp"

class Rectangle: public Shape {
    int length, breadth;
    public:
        Rectangle(int length, int breadth);
        double getArea();
        double getPerimeter();
};

#endif