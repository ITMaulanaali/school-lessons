#include "Skala.hpp"


long Skala::skala(int jarakPeta, long jarakSebenarnya){
    return jarakSebenarnya / jarakPeta;
}

long Skala::jarakSebenarnya(int jarakPeta, long skala){
    return jarakPeta * skala;
}

int Skala::jarakPeta(long skala, long jarakSebenarnya){
    return jarakSebenarnya / skala;
}