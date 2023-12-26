#include "desktop.hpp"
#include<iostream>
using namespace std;

void Desktop::setMonitor(string monitor) {
    this->monitor = monitor;
}

void Desktop::setKeyboard(string keyboard) {
    this->keyboard = keyboard;
}

void Desktop::setMouse(string mouse) {
    this->mouse = mouse;
}

void Desktop::showSpecs() {
    cout<<"Monitor:"<<monitor<<" Keyboard:"<<keyboard<<" Mouse:"<<mouse<<endl;
}
