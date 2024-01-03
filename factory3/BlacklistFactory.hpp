#pragma once
#ifndef BLACKLISTFACTORY_H
#define BLACKLISTFACTORY_H
#include <iostream>
#include "Blacklist.hpp"

class BlacklistFactory {
    public:
        static Blacklist* createBlacklist(std::string name, std::string ride, int rank, char type);
};

#endif