#pragma once
#ifndef FEMALEBLACKLIST_H
#define FEMALEBLACKLIST_H
#include <iostream>
#include "Blacklist.hpp"

class FemaleBlacklist: public Blacklist {
    public:
        FemaleBlacklist(std::string name, std::string ride, int rank);
        void displayBlacklist();
};

#endif