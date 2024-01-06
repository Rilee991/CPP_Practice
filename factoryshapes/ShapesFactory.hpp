#pragma once
#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "Shape.hpp"
#include "enum.hpp"

class ShapesFactory {
    public:
        static Shape* getShape(Shapes type);
};

#endif