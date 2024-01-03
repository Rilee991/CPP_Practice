#pragma once
#ifndef BLACKLIST_H
#define BLACKLIST_H
#include <iostream>

class Blacklist {
    protected:
        std::string name;
        std::string ride;
        int rank;
        char gender;

        public:
            Blacklist(std::string name, std::string ride, int rank, char gender);
            virtual void displayBlacklist() = 0;
};

#endif