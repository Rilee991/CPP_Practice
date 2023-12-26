#ifndef DESKTOPDIRECTOR
#define DESKTOPDIRECTOR
#include "desktopBuilder.hpp"
using namespace std;

class DesktopDirector {
    private:
        DesktopBuilder* desktopBuilder;
    public:
        DesktopDirector(DesktopBuilder* desktopBuilder) {
            this->desktopBuilder = desktopBuilder;
        }

        Desktop* getBuilder() {
            return this->desktopBuilder->getDesktop();
        }

        Desktop* buildDesktop() {
            desktopBuilder->buildKeyboard();
            desktopBuilder->buildMonitor();
            desktopBuilder->buildMouse();
            return desktopBuilder->getDesktop();
        }
};

#endif
