#include "ShapesFactory.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

Shape* ShapesFactory::getShape(Shapes type) {
    switch(type) {
        case Shapes::CIRCLE: {
            int rad;
            cin>>rad;
            return new Circle(rad);
        }
        case Shapes::RECTANGLE: {
            int len, bre;
            cin>>len>>bre;
            return new Rectangle(len, bre);
        }
        case Shapes::SQUARE: {
            int side;
            cin>>side;
            return new Square(side);
        }
        default: {
            cout<<"Invalid choice!\n";
            return NULL;
        }
    }
}