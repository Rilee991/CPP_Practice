#include <iostream>
using namespace std;

class Animal {
    protected:
        int legs;
    public:
        virtual int getLegs() = 0;
};

int Animal::getLegs() {
    return 0;
}

class Human: public Animal {
    public:
        Human() {
            legs = 2;
        }
        int getLegs() {
            return legs;
        }
};

class Cow: public Animal {
    public:
        Cow() {
            legs = 4;
        }
        int getLegs() {
            return legs;
        }
};

int main() {
    Animal *a = new Human();
    cout<<"Legs:"<<a->getLegs()<<endl;
}
