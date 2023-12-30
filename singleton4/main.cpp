#include <iostream>
#include <thread>
#include "Config.hpp"
using namespace std;

void createInstance() {
    Config *config1 = Config::getConfigInstance();
    config1->setConfig(5);
}

int main() {

    // Approach - 1
    // ....threads use config1

    // Approach - 2
    // Mutex locks
    thread t1(createInstance), t2(createInstance), t3(createInstance);

    t1.join();
    t2.join();
    t3.join();
}
