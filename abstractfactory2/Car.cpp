#include <iostream>
#include "Car.hpp"
using namespace std;

Car::Car(string n) {
    this->name = n;
}

void Car::setTire(Tire* t) {
    this->tire = t;
}

void Car::setBody(Body* b) {
    this->body = b;
}

void Car::displayCar() {
    cout<<"Car info\n";
    cout<<"Name:"<<name<<", Body details:"<<body->getBodyDetails()<<", Tire details:"<<tire->getTireDetails()<<"\n";
}
