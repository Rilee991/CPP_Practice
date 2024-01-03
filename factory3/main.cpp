#include <iostream>
#include "BlacklistFactory.hpp"
#include "Blacklist.hpp"

int main() {
    Blacklist* b1 = BlacklistFactory::createBlacklist("Razor", "BMW M3 GTR", 1, 'M');
    Blacklist* b2 = BlacklistFactory::createBlacklist("Bull", "Mercedes Benz SLR McLaren", 2, 'M');
    Blacklist* b3 = BlacklistFactory::createBlacklist("Jewels", "Ford Mustang GT", 8, 'F');
    Blacklist* b4 = BlacklistFactory::createBlacklist("Izzy", "Mazda IS300", 13, 'F');
    Blacklist* b5 = BlacklistFactory::createBlacklist("Ming", "Lamborghini Gallardo", 6, 'M');

    b1->displayBlacklist();
    b2->displayBlacklist();
    b3->displayBlacklist();
    b4->displayBlacklist();
    b5->displayBlacklist();
}