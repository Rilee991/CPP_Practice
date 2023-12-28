#include <iostream>
#include "Logger.hpp"
using namespace std;

int Logger::ctr = 0;
Logger* Logger::instance = NULL;
mutex Logger::mtx;

Logger::Logger() {
    cout<<"Logger instance created. Ctr: "<<++ctr<<"\n";
}

void Logger::logMsg(string msg) {
    cout<<"Msg logged:"<<msg<<"\n";
}

Logger* Logger::getLogger() {
    // if(!instance) {
        // mtx.lock();
        if(!instance) {
            instance = new Logger();
        }
        // mtx.unlock();
    // }

    return instance;
}