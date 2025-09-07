#include "Persegi.hpp"

int Persegi::luas(int alas, int tinggi){
    return alas * tinggi;
}

int Persegi::alas(int luas, int tinggi){
    return luas / tinggi;
}

int Persegi::tinggi(int luas, int alas){
    return luas / alas;
}

int Persegi::keliling(int alas){
    return alas * 4;
}