#ifndef ARITMATIKA_HPP
#define ARITMATIKA_HPP

#include <string>
#include <vector>
#include <sstream>

class Aritmatika{

    public:
        double pangkat(int bilangan, int pangkat);
        std::string prima(int bilPrima);
        std::string fpb(std::string primaSatu, std::string primaDua);
        int kpk(int bil1, int bil2);
        float sederhanakanPecahan(int pembilang, int penyebut);
};

#endif