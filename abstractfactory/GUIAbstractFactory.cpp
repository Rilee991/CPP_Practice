#include "IFactory.cpp"
#include "MacFactory.cpp"
#include "WinFactory.cpp"

class GUIAbstractFactory {
    public:
        static IFactory* createFactory (std::string osType) {
            if(osType == "mac") return new MacFactory();
            else if(osType == "win") return new WinFactory();

            return new MacFactory();
        }
};