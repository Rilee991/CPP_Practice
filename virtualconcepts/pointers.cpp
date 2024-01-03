#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 10;
    int &ref = x;
    // &ref = y; //This gives error. References cannot be made to change to represent other variable.

    // ref = 66;
    cout<<x;
}
