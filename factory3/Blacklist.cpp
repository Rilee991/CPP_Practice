#include <iostream>
#include "Blacklist.hpp"

Blacklist::Blacklist(std::string name, std::string ride, int rank, char gender) {
    this->name = name;
    this->ride = ride;
    this->rank = rank;
    this->gender = gender;
}