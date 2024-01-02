#pragma once
#ifndef GAMECONFIG_H
#define GAMECONFIG_H
#include <iostream>
#include <mutex>
using namespace std;

class GameConfig {
    int brightness;
    int volume;
    int sensitivity;
    static int ctr;
    static GameConfig* instance;
    static mutex mtx;

    GameConfig(int b, int v, int s);
    GameConfig(GameConfig &config);
    GameConfig* operator+(const GameConfig &rhs);

    public:
        void displayConfigs();
        static GameConfig* createInstance(int b, int v, int s);
        int getSensitivity();
        void setSensitivity(int sensitivity);
        int getVolume();
        int getBrightness();
        void setVolume(int volume);
        void setBrightness(int brightness);
};

#endif