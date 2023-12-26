#ifndef DESKTOPBUILDER_H
#define DESKTOPBUILDER_H
#include "desktop.hpp"
using namespace std;

class DesktopBuilder {
    protected:
        Desktop *desktop;

    public:
        DesktopBuilder () {
            desktop = new Desktop();
        }
        virtual void buildMonitor() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildMouse() = 0;
        virtual Desktop* getDesktop() {
            return this->desktop;
        }
};

#endif
