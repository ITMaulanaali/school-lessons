

class Penjumlahan{


    public:
        int sifatPenjumlahan(int bil1, int bil2){
            if(bil2 < 0){
                int setPositif = (-bil2);
                return bil1 - setPositif;
            }

            return bil1 + bil2;
        }
};

class Pengurangan{


    public:
    int sifatPengurangan(int bil1, int bil2){
        if(bil2 < 0 && bil1 >= 0){
            int setPositif = (-bil2);
            return bil1 + setPositif;
        }else if(bil1 < 0 && bil2 >= 0){
            int setPositif = (-bil1);
            int setNegatif = -(setPositif + bil2);
            return setNegatif;
        }else if(bil1 < 0 && bil2 < 0){
            int setPositif = (-bil2);
            return bil1 + setPositif;
        }

        return bil1 - bil2;
    }
};