#include "Aritmatika.hpp"

int Aritmatika::barisan(int sukuPertama, int sukuKedua, int nomorSukuYangDicari){
    int selisih = sukuKedua - sukuPertama;
    int banyakPerkalianKeN = nomorSukuYangDicari - 1;

    return sukuPertama + banyakPerkalianKeN * selisih;
}

int Aritmatika::deret(int sukuPertama, int jumlahSukuN, int nilaiSukuN){
    int setengahJumlahSukuN = jumlahSukuN / 2;
    int hasilSukuAwalDanSukuAkhir = sukuPertama + nilaiSukuN;

    return setengahJumlahSukuN * hasilSukuAwalDanSukuAkhir;
}