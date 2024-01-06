#include "Logger.hpp"

int Logger::ctr = 0;
Logger* Logger::instance = NULL;
mutex Logger::mtx;

Logger::Logger() {
    std::cout<<"Instance created:"<<++ctr<<"\n";
}

Logger::Logger(Logger &logger) {
    std::cout<<"Instance created using copy constructor:"<<++ctr<<"\n";
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

Logger* Logger::operator+(Logger &rhs) {
    return new Logger();
}

void Logger::printLog(std::string log) {
    std::cout<<"Log is:"<<log<<"\n";
}
