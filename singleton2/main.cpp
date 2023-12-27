#include<iostream>
#include "logger.hpp"
#include<thread>
using namespace std;

void createLogger() {
    Logger *logger = Logger::createInstance();
    Logger *cLogger(logger);
    logger->log("This is a msg");
    cLogger->log("Copy constructor calling");
}

int main() {
    thread t1(createLogger), t2(createLogger), t3(createLogger);

    t1.join();
    t2.join();
    t3.join();

    // Logger *logger2 = Logger::createInstance();
    // logger2->log("This is a 2nd msg");;

    return 0;
}