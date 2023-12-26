#include<iostream>
#include"logger.hpp"
using namespace std;

int Logger::ctr = 0;
mutex Logger::mtx;
Logger* Logger::loggerInstance = NULL;

Logger::Logger() {
    ctr++;
    cout<<"New instance created: "<<ctr<<"\n";
}

void Logger::log(string msg) {
    cout<<msg<<"\n";
}

Logger* Logger::createLogger() {
    if(!loggerInstance) {
        mtx.lock();
        if(!loggerInstance) {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }

    return loggerInstance;
}