#pragma once
#ifndef MASALA_HPP
#define MASALA_HPP
#include<iostream>
using namespace std;

class Masala {
    protected:
        string name;
        string color;
        int qty;

    public:
        virtual void addColor(string color) {}
        virtual void addQuantity(int qty) {}
        virtual void applyLabel(string name) {}
        virtual void prepareMasala() {}
        virtual void displayMasala() {}

        // No vtable error will come if we don't provide a default implementation to virtual funcs by making it = 0;
};
#endif