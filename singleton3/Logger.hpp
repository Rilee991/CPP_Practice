#pragma once
#ifndef LOGGERHPP
#define LOGGERHPP
#include <iostream>
#include <mutex>
using namespace std;

class Logger {
    static mutex mtx;
    static int ctr;
    static Logger* instance;
    Logger();
    Logger(Logger &logger);
    public:
        void logMsg(string msg);
        static Logger* createInstance();
};

#endif