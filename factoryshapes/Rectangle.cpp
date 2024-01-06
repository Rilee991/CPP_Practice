#include "Rectangle.hpp"

Rectangle::Rectangle(int length, int breadth) {
    this->length = length;
    this->breadth = breadth;
    type = "Rectangle";
}

double Rectangle::getArea() {
    return length * breadth * 1.0;
}

double Rectangle::getPerimeter() {
    return 2.0 * (length + breadth);
}
