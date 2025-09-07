#ifndef PERSEGI_HPP
#define PERSEGI_HPP

class Persegi{
//Luas = a x t
//Keliling = 4x sisi

    public:
        int luas(int alas, int tinggi);
        int alas(int luas, int tinggi);
        int tinggi(int luas, int alas);
        int keliling(int alas);
};

#endif