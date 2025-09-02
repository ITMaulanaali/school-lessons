<<<<<<< HEAD


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
=======
#ifndef SKALA_HPP
#define SKALA_HPP

class Skala{
    public:
        long skala(int jarakPeta, long jarakSebenarnya);
        long jarakSebenarnya(int jarakPeta, long skala);
        int jarakPeta(long skala, long jarakSebenarnya);
};

#endif
>>>>>>> 0fc7294 (Skala-done)
