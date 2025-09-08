#include "Perpangkatan.hpp"

long Perpangkatan::pangkat(int a, int b, int pangkat){
    long hasil;

    if(pangkat == 2){
        hasil = (a+b) * (a+b);
    }else if(pangkat > 2){
        hasil = (a+b);
        for(int i=1; i<pangkat; i++){
            hasil = hasil * (a+b);
        }
    }

    return hasil;
}