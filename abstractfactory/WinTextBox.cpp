#include "ITextBox.cpp"

class WinTextBox: public ITextBox {
    public:
        void showText() {
            std::cout<<"Windows text\n";
        }
};
