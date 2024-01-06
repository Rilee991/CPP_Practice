#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<mutex>
using namespace std;

class Logger {
    static int ctr;
    static Logger* instance;
    static mutex mtx;
    Logger();
    Logger(Logger &logger);
    Logger* operator+(Logger &rhs);
    
    public:
        static Logger* createInstance();
        void printLog(std::string log);
};

#endif