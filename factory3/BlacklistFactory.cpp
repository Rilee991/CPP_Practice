#include <iostream>
#include "BlacklistFactory.hpp"
#include "MaleBlacklist.hpp"
#include "FemaleBlacklist.hpp"

Blacklist* BlacklistFactory::createBlacklist(std::string name, std::string ride, int rank, char type) {
    switch (type) {
        case 'M':
            return new MaleBlacklist(name,ride,rank);
        case 'F':
            return new FemaleBlacklist(name,ride,rank);
        default:
            return NULL;
    }
}
