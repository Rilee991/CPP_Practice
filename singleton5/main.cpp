#include <iostream>
#include <thread>
#include "Logger.hpp"

void executeThread() {
    Logger *logger = Logger::createInstance();
    logger->printLog("This is a log...");
}

int main() {
    // Step - 1 (Displaying different kinds of methods which can result to creating multiple objects)
    // Logger *logger = new Logger();
    // logger->printLog("This is a log 1");

    // Logger *logger2 = new Logger();
    // logger2->printLog("This is a log 2");

    // Logger *logger3 = new Logger(*logger2);
    // logger3->printLog("This is a log 3");

    // Logger* logger4 = (*logger3) + (*logger3);
    // logger4->printLog("This is a log 4");

    // Step - 2 (Demonstrating that using createInstance static method the first 2 methods don't create multiple objects but last 2 can)
    // Logger *logger = Logger::createInstance();
    // logger->printLog("This is a log 1");

    // Logger *logger2 = Logger::createInstance();
    // logger2->printLog("This is a log 2");

    // Logger *logger3 = new Logger(*logger2);
    // logger3->printLog("This is a log 3");

    // Logger* logger4 = (*logger3) + (*logger3);
    // logger4->printLog("This is a log 4");

    // Step - 3 (Thread Safety problem and demo)
    std::thread t1(executeThread), t2(executeThread), t3(executeThread);

    t1.join();
    t2.join();
    t3.join();
}