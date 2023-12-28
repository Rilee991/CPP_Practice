#include <iostream>
#include <thread>
#include "Logger.hpp"
using namespace std;

void createLogger() {
    Logger *logger = Logger::getLogger();
    logger->logMsg("This is a sample msg");
}

int main() {
    Logger *logger = Logger::getLogger();
    thread t1(createLogger), t2(createLogger), t3(createLogger);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}