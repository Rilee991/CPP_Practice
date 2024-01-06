#include "Circle.hpp"

Circle::Circle(int radius) {
    this->radius = radius;
    type = "Circle";
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

double Circle::getPerimeter() {
    return 2 * 3.14 * radius;
}
