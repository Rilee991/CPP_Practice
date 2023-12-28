#include<iostream>
#include "MasalaFactory.hpp"
using namespace std;

int main() {
    int mtype, qty;
    string color, name;
    cin>>mtype>>qty>>color>>name;

    Masala* masala = MasalaFactory::createFactory(mtype);
    masala->addColor(color);
    masala->addQuantity(qty);
    masala->applyLabel(name);
    masala->prepareMasala();
    masala->displayMasala();
}