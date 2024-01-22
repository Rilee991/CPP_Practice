#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include "EntityType.hpp"
#include <iostream>
using namespace std;

class Utility {
    public:
        static string getTypeString(EntityType);
};

#endif