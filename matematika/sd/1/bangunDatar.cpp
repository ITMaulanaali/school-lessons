

class Trapesium{
    private:

    public:
        int luas(int sisiSejajar1, int sisiSejajar2, int tinggi){
            return (sisiSejajar1 + sisiSejajar2) * tinggi / 2;
        }
};

class JajarGenjang{

    public:
        int luas(int sisiSejajarAlas1, int sisiSejajarTinggi1){
            return sisiSejajarAlas1 * sisiSejajarTinggi1;
        }
};

class Persegi{
    

    public:
        int luas(int sisi1, int sisi2){
            return sisi1*sisi2;
        }
};

class Segitiga{


    public:
        int luas(int alas, int tinggi){
            return (alas * tinggi) / 2;
        }

        // int sisiMiring(int alas, int tinggi){
        //     int hasilKuadrat = (alas*alas) * (tinggi*tinggi);
        //     //akar hasilKuadrat
        //     return 
        // }
};

class BelahKetupat{

};

class LayangLayang{

};