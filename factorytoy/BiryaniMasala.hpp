#pragma once
#ifndef BIRYANI_HPP
#define BIRYANI_HPP
#include<iostream>
#include "Masala.hpp"
using namespace std;

class BiryaniMasala: public Masala {
    public:
        void addColor(string color);
        void addQuantity(int qty);
        void applyLabel(string name);
        void prepareMasala();
        void displayMasala();
};
#endif