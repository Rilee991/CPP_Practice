#pragma once
#ifndef MUTTON_HPP
#define MUTTON_HPP
#include<iostream>
#include "Masala.hpp"
using namespace std;

class MuttonMasala: public Masala {
    public:
        void addColor(string color);
        void addQuantity(int qty);
        void applyLabel(string name);
        void prepareMasala();
        void displayMasala();
};
#endif