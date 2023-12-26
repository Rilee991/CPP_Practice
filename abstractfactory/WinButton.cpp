#include "IButton.cpp"

class WinButton: public IButton {
    public:
        void click() {
            std::cout<<"Windows button clicked\n";
        }
};
