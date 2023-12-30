#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
using namespace std;

class Config {
    static int ctr;
    static Config* instance;
    Config();
    Config(const Config &config);
    Config* operator+(const Config &rhs);
    public:
        void setConfig(int configId);
        static Config* getConfigInstance();
};

#endif