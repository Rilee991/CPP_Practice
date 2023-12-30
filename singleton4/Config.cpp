#include <iostream>
#include <mutex>
#include "Config.hpp"
using namespace std;

mutex mtx;
int Config::ctr = 0;
Config* Config::instance = NULL;

Config::Config() {
    cout<<"Config is created. Instances count:"<<++ctr<<"\n";
}

Config::Config(const Config &config) {
    cout<<"Config is created using copyconstructor. Instances count:"<<++ctr<<"\n";
}

Config* Config::operator+(const Config &rhs) {
    cout<<"Config is created using operator overloading. Instances count:"<<++ctr<<"\n";
    Config *config;
    return config;
}

void Config::setConfig(int configId) {
    cout<<"Config is set with id:"<<configId<<endl;
}

Config* Config::getConfigInstance() {
    if(!instance) {
        mtx.lock();
        if(!instance) {
            instance = new Config();
        }
        mtx.unlock();
    }

    return instance;
}
