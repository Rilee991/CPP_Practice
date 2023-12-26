#ifndef IFactory
#define IFactory

#include "IButton.cpp"
#include "ITextBox.cpp"

class IFactory {
    public:
        virtual IButton* createButton() = 0;
        virtual ITextBox* createTextBox() = 0;
};

#endif