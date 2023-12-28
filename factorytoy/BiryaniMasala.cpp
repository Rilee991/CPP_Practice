#include<iostream>
#include "BiryaniMasala.hpp"
using namespace std;

void BiryaniMasala::prepareMasala() {
    cout<<"Masala Prepared\n";
}

void BiryaniMasala::applyLabel(string name) {
    this->name = name;
    cout<<"Name added\n";
}

void BiryaniMasala::addColor(string color) {
    this->color = color;
    cout<<"Color Added\n";
}

void BiryaniMasala::addQuantity(int qty) {
    this->qty = qty;
    cout<<"Quantity loaded\n";
}

void BiryaniMasala::displayMasala() {
    cout<<"Masala props - Name:"<<name<<" | color:"<<color<<" | quantity:"<<qty<<"\n";
}
