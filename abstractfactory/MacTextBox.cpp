#include "ITextBox.cpp"

class MacTextBox: public ITextBox {
    public:
        void showText() {
            std::cout<<"Mac text\n";
        }
};
