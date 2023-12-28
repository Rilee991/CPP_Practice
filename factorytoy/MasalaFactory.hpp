#pragma once
#ifndef FACTORY_HPP
#define FACTORY_HPP
#include<iostream>
#include "Masala.hpp"
using namespace std;

class MasalaFactory {
    public:
        static Masala* createFactory(int masalaType);
};
#endif