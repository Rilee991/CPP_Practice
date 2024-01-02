#include <iostream>
#include "GameConfig.hpp"
using namespace std;

int GameConfig::ctr = 0;
GameConfig* GameConfig::instance = NULL;
mutex GameConfig::mtx;

GameConfig::GameConfig(int b, int v, int s) {
    cout<<"Instance created: "<<++ctr<<"\n";
    brightness = b;
    volume = v;
    sensitivity = s;
}

void GameConfig::displayConfigs() {
    cout<<"Configs\nBrightness:"<<brightness<<", Volume:"<<volume<<", Sensitivity:"<<sensitivity<<"\n";
}

GameConfig* GameConfig::createInstance(int b, int v, int s) {
    if(!instance) {
        mtx.lock();
        if(!instance) {
            instance = new GameConfig(b,v,s);
        }
        mtx.unlock();
    }

    return instance;
}

int GameConfig::getSensitivity() {
    return this->sensitivity;
}
void GameConfig::setSensitivity(int sensitivity) {
    this->sensitivity = sensitivity;
}
int GameConfig::getVolume() {
    return this->volume;
}
void GameConfig::setVolume(int volume) {
    this->volume = volume;
}
int GameConfig::getBrightness() {
    return this->brightness;
}
void GameConfig::setBrightness(int brightness) {
    this->brightness = brightness;
}