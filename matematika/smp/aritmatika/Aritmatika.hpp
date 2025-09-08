#ifndef ARITMATIKA_HPP
#define ARITMATIKA_HPP

class Aritmatika{

    public:
        int barisan(int sukuPertama, int sukuKedua, int nomorSukuYangDicari);
        int deret(int sukuPertama, int jumlahSukuN, int nilaiSukuN);
};

#endif

/*
Rumus barisan atau nilai suku n
Un = U1 + (n-1) * selisih

Rumus deret atau penjumlahan dari suku awal hingga suku ke n
Terdapat pola unik dari deret ini. Yang mana penjumalahan sukuAwal dengan sukuAkhirnya akan selalu memiliki hasil sama sebanyak setengah dari jumlahSukuN
Sn = n/2 (U1 * Un)
*/