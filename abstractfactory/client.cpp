#include<iostream>
#include "Ifactory.cpp"
#include "GUIAbstractFactory.cpp"

using namespace std;

int main() {
    string osType;
    cin>>osType;

    IFactory* guiFactory = GUIAbstractFactory::createFactory(osType);
    // IButton* button = guiFactory->createButton();
    // ITextBox* textBox = guiFactory->createTextBox();

    // button->click();
    // textBox->showText();

    return 0;
}