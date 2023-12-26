#include "IFactory.cpp"
#include "WinButton.cpp"
#include "WinTextBox.cpp"

class WinFactory: public IFactory {
    public:
        IButton* createButton () {
            return new WinButton();
        }

        ITextBox* createTextBox () {
            return new WinTextBox();
        }
};
