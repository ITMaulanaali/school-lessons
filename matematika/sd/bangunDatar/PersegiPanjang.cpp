#include "PersegiPanjang.hpp"

    int PersegiPanjang::luas(int panjang, int lebar){
        return panjang * lebar;
    }

    int PersegiPanjang::keliling(int panjang, int lebar){
        return (2 * panjang) + (2 * lebar);
    }

    int PersegiPanjang::panjang(int luas, int lebar){
        return luas / lebar;
    }

    int PersegiPanjang::lebar(int luas, int panjang){
        return luas / panjang;
    }