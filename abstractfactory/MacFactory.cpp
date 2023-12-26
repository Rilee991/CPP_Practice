#include "IFactory.cpp"
#include "MacButton.cpp"
#include "MacTextBox.cpp"

class MacFactory: public IFactory {
    public:
        IButton* createButton () {
            return new MacButton();
        }

        ITextBox* createTextBox () {
            return new MacTextBox();
        }
};
