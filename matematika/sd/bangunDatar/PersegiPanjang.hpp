#ifndef PERSEGIPANJANG_HPP
#define PERSEGIPANJANG_HPP

class PersegiPanjang{
//Luas = p x l
//Keliling = 2p + 2l = (2 * p) + (2 * l) = 4 + 2l + 2p + pl

    int luas(int panjang, int lebar);
    int keliling(int panjang, int lebar);
    int panjang(int luas, int lebar);
    int lebar(int luas, int panjang);

};

#endif