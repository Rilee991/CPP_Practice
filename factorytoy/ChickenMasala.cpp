#include<iostream>
#include "ChickenMasala.hpp"
using namespace std;

void ChickenMasala::prepareMasala() {
    cout<<"Masala Prepared\n";
}

void ChickenMasala::applyLabel(string name) {
    this->name = name;
    cout<<"Name added\n";
}

void ChickenMasala::addColor(string color) {
    this->color = color;
    cout<<"Color Added\n";
}

void ChickenMasala::addQuantity(int qty) {
    this->qty = qty;
    cout<<"Quantity loaded\n";
}

void ChickenMasala::displayMasala() {
    cout<<"Masala props - Name:"<<name<<" | color:"<<color<<" | quantity:"<<qty<<"\n";
}
