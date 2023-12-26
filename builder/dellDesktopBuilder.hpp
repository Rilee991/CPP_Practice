#ifndef DELLDESKTOPBUILDER_H
#define DELLDESKTOPBUILDER_H
#include "desktopBuilder.hpp"
using namespace std;

class DellDesktopBuilder: public DesktopBuilder {
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
};

#endif
