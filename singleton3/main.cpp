#include<iostream>
#include<thread>
#include "Logger.hpp"
using namespace std;

void getInstance() {
    Logger* logger = Logger::createInstance();
    Logger *copyLogger(logger);
    logger->logMsg("This is a message");
    copyLogger->logMsg("This is a new msg");
}

int main() {
    thread t1(getInstance);
    thread t2(getInstance);
    thread t3(getInstance);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
