#ifndef DESKTOP_H
#define DESKTOP_H
#include<string>
using namespace std;

class Desktop {
    string monitor, keyboard, mouse;

    public:
        void setMonitor(string monitor);
        void setKeyboard(string keyboard);
        void setMouse(string mouse);
        void showSpecs();
};

#endif
