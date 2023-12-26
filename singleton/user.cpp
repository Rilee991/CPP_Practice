#include<iostream>
#include<thread>
#include "logger.hpp"
using namespace std;

void user1Logs () {
    Logger *logger1 = Logger::createLogger();
    logger1->log("User1");
}

void user2Logs () {
    Logger *logger2 = Logger::createLogger();
    logger2->log("User2");
}

int main() {
    thread t1(user1Logs);
    thread t2(user2Logs);
    thread t3(user2Logs);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}