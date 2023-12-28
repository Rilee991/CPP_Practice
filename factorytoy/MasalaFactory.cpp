#include "MasalaFactory.hpp"
#include "ChickenMasala.hpp"
#include "BiryaniMasala.hpp"
#include "MuttonMasala.hpp"
using namespace std;

Masala* MasalaFactory::createFactory(int masalaType) {
    switch(masalaType) {
        case 1: {
            return new ChickenMasala();
        }
        case 2: {
            return new BiryaniMasala();
        }
        case 3: {
            return new MuttonMasala();
        }
        default: {
            cout<<"Invalid masala type\n";
            return NULL;
        }
    }
}