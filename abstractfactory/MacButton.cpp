#include "IButton.cpp"

class MacButton: public IButton {
    public:
        void click() {
            std::cout<<"Mac button clicked\n";
        }
};
