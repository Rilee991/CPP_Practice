#pragma once
#ifndef logger_h
#define logger_h
#include<iostream>
#include<mutex>
using namespace std;

class Logger {
    static int ctr;
    static Logger* instance;
    static mutex mtx;
    Logger();
    Logger(Logger* logger);
    public:
        void log(string msg);
        static Logger* createInstance();
};

#endif