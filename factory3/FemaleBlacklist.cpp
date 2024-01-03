#include <iostream>
#include "FemaleBlacklist.hpp"

FemaleBlacklist::FemaleBlacklist(std::string name, std::string ride, int rank): Blacklist(name, ride, rank, 'F') {}

void FemaleBlacklist::displayBlacklist() {
    std::cout<<"Blacklist details\n";
    std::cout<<"Name: "<<name<<" | Ride: "<<ride<<" | Rank: "<<rank<<" | "<<"Gender: "<<gender<<"\n";
}