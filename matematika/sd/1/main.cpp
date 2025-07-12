#include "aritmetika.h"
#include "himpunan.hpp"
#include "operasiBilanganBulat.cpp"
#include "bangunDatar.cpp"
#include <iostream>
#include <string>

int main(){

    himpunan kotak;
    kotak.inputCollection(5,4,4,16,7,8,9);
    kotak.inputCollection(5,9,12,14,15,16,16,17,20,22,24);
    kotak.inputCollection(1,2,3,4,5);
    kotak.cetak();
    return 0;
}



//sudo ln -s /etc/nginx/sites-available/serverdata.conf /etc/nginx/sites-enabled/serverdata.conf