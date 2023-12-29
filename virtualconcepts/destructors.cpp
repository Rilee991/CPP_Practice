#include <iostream>
using namespace std;

class Parent {
    public:
        Parent() {
            cout<<"Parent Ctr\n";
        }
        virtual ~Parent() {
            cout<<"Parent dtr\n";
        }
};

class Child: public Parent {
    public:
        Child() {
            cout<<"Child Ctr\n";
        }
        ~Child() {
            cout<<"Child dtr\n";
        }
};

int main() {
    Parent *p = new Child();
    delete p;
}