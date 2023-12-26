#include "hpDesktopBuilder.hpp"
using namespace std;

void HpDesktopBuilder::buildMonitor() {
    this->desktop->setMonitor("HP monitor");
}

void HpDesktopBuilder::buildKeyboard() {
    this->desktop->setKeyboard("HP keyboard");
}

void HpDesktopBuilder::buildMouse() {
    this->desktop->setMouse("HP mouse");
}
