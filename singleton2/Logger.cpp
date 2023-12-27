#include<iostream>
#include "logger.hpp"
using namespace std;

int Logger::ctr = 0;
Logger* Logger::instance = NULL;
mutex Logger::mtx;
//2000098
Logger::Logger() {
    cout<<"Instance created for logger - Instances:"<<++ctr<<"\n";
}

Logger::Logger(Logger *logger) {
    cout<<"Copy constructor is created, instances:"<<++ctr<<"\n";
}

void Logger::log(string msg) {
    cout<<"Msg:"<<msg<<"\n";
}

Logger* Logger::createInstance() {
    if(!instance) {
        mtx.lock();
        if(!instance) {
            instance = new Logger();
        }
        mtx.unlock();
    }

    return instance;
}