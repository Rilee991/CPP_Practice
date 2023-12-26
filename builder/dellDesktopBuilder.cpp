#include "dellDesktopBuilder.hpp"
using namespace std;

void DellDesktopBuilder::buildMonitor() {
    this->desktop->setMonitor("Dell monitor");
}

void DellDesktopBuilder::buildKeyboard() {
    this->desktop->setKeyboard("Dell keyboard");
}

void DellDesktopBuilder::buildMouse() {
    this->desktop->setMouse("Dell mouse");
}
