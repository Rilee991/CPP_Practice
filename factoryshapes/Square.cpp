#include "Square.hpp"

Square::Square(int side) {
    this->side = side;
    type = "Square";
}

double Square::getArea() {
    return side * side * 1.0;
}

double Square::getPerimeter() {
    return 4.0 * side;
}
