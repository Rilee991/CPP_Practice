#ifndef HPDESKTOPBUILDER_H
#define HPDESKTOPBUILDER_H
#include "desktopBuilder.hpp"
using namespace std;

class HpDesktopBuilder: public DesktopBuilder {
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
};

#endif
