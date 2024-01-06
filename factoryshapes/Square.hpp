#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.hpp"

class Square: public Shape {
    int side;
    public:
        Square(int side);
        double getArea();
        double getPerimeter();
};

#endif