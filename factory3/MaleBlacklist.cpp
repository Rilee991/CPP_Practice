#include <iostream>
#include "MaleBlacklist.hpp"

MaleBlacklist::MaleBlacklist(std::string name, std::string ride, int rank): Blacklist(name, ride, rank, 'M') {}

void MaleBlacklist::displayBlacklist() {
    std::cout<<"Blacklist details\n";
    std::cout<<"Name: "<<name<<" | Ride: "<<ride<<" | Rank: "<<rank<<" | "<<"Gender: "<<gender<<"\n";
}