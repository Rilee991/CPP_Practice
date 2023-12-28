#pragma once
#ifndef CHICKEN_HPP
#define CHICKEN_HPP
#include<iostream>
#include "Masala.hpp"
using namespace std;

class ChickenMasala: public Masala {
    public:
        void addColor(string color);
        void addQuantity(int qty);
        void applyLabel(string name);
        void prepareMasala();
        void displayMasala();
};
#endif