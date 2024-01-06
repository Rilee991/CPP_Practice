#include "ShapesFactory.hpp"
#include "Shape.hpp"

int main() {
    int type;
    cin>>type;
    Shape* shape = ShapesFactory::getShape(type == 1 ? Shapes::CIRCLE : (type == 2 ? Shapes::RECTANGLE : (type == 3 ? Shapes::SQUARE : Shapes::DEFAULT)));
    if(shape) cout<<"Area:"<<shape->getArea()<<", Perimeter:"<<shape->getPerimeter();
}
