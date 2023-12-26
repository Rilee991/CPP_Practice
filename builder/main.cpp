#include "hpDesktopBuilder.hpp"
#include "dellDesktopBuilder.hpp"
#include "director.hpp"

using namespace std;

int main() {
    HpDesktopBuilder *hpDesktopBuilder = new HpDesktopBuilder();
    DellDesktopBuilder *dellDesktopBuilder = new DellDesktopBuilder();

    DesktopDirector *director1 = new DesktopDirector(hpDesktopBuilder);
    DesktopDirector *director2 = new DesktopDirector(dellDesktopBuilder);

    Desktop* dellDesktop = director2->buildDesktop();
    Desktop* hpDesktop = director1->buildDesktop();

    dellDesktop->showSpecs();
    hpDesktop->showSpecs();
    
    return 0;
}