

class Skala{
    public:
        long skala(int jarakPeta, long jarakSebenarnya){
            return jarakSebenarnya / jarakPeta;
        }

        long jarakSebenarnya(int jarakPeta, long skala){
            return jarakPeta * skala;
        }

        int jarakPeta(long skala, long jarakSebenarnya){
            return jarakSebenarnya / skala;
        }
};