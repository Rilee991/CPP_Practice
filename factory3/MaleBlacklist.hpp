#pragma once
#ifndef MALEBLACKLIST_H
#define MALEBLACKLIST_H
#include <iostream>
#include "Blacklist.hpp"

class MaleBlacklist: public Blacklist {
    public:
        MaleBlacklist(std::string name, std::string ride, int rank);
        void displayBlacklist();
};

#endif