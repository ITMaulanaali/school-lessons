#ifndef PERBANDINGAN_HPP
#define PERBANDINGAN_HPP

#include <vector>
#include <string>
#include <iostream>

class Perbandingan{
    private:
        std::string subjek, object;
        int valueSubject, valueObject;

    public:
        void inputDiketahui(std::string subject, int valueSubject, std::string object, int valueObject);
        float hasilSenilaiA(int value);
        float hasilSenilaiB(int value);
        float hasilBerbalikNilaiA(int value);
        float hasilBerbalikNilaiB(int value);
        float perbandinganBertingkat();
};

#endif