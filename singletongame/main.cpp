#include <iostream>
#include <thread>
#include "GameConfig.hpp"
using namespace std;

void getInstanceByThread() {
    GameConfig *config = GameConfig::createInstance(5,6,7);
    config->displayConfigs();
}

void threadOps() {
    GameConfig *config = GameConfig::createInstance(5,6,7);
    config->displayConfigs();
}

int main() {
    GameConfig *config = GameConfig::createInstance(5,6,7);
    GameConfig *config2 = new GameConfig(*config);
    config2->displayConfigs();
    // thread t1(getInstanceByThread), t2(getInstanceByThread), t3(getInstanceByThread);
    // thread t1(threadOps), t2(threadOps), t3(threadOps);

    // t1.join();
    // t2.join();
    // t3.join();
}