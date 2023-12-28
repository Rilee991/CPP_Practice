#include<iostream>
#include "MuttonMasala.hpp"
using namespace std;

void MuttonMasala::prepareMasala() {
    cout<<"Masala Prepared\n";
}

void MuttonMasala::applyLabel(string name) {
    this->name = name;
    cout<<"Name added\n";
}

void MuttonMasala::addColor(string color) {
    this->color = color;
    cout<<"Color Added\n";
}

void MuttonMasala::addQuantity(int qty) {
    this->qty = qty;
    cout<<"Quantity loaded\n";
}

void MuttonMasala::displayMasala() {
    cout<<"Masala props - Name:"<<name<<" | color:"<<color<<" | quantity:"<<qty<<"\n";
}
