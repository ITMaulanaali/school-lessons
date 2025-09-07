#include "Berpangkat.hpp"

int Berpangkat::pangkat(int bilangan, int pangkat){
    if (pangkat == 0) {
        return 1;
    } else {
        return bilangan * Berpangkat::pangkat(bilangan, pangkat - 1);
    }
}