#include "Perbandingan.hpp"

void Perbandingan::inputDiketahui(std::string subject, int valueSubject, std::string object, int valueObject){
    this->subjek = subject;
    this->valueSubject = valueSubject;
    this->object = object;
    this->valueObject = valueObject;
}

float Perbandingan::hasilSenilaiA(int valueB){
    float nilaiPecah = this->valueSubject / (float)this->valueObject;

    std::cout << this->subjek << " : " << this->valueSubject << " ---> " << this->object << " :" << this->valueObject << std::endl;
    std::cout << this->subjek << " : x" << " ---> " << this->object << " :" << valueB << std::endl;
    std::cout << "A adalah" << std::endl;
    return nilaiPecah * valueB;
};

float Perbandingan::hasilSenilaiB(int valueA){
    float nilaiPecah = this->valueObject / (float)this->valueSubject;

    std::cout << this->subjek << " : " << this->valueSubject << " ---> " << this->object << " :" << this->valueObject << std::endl;
    std::cout << this->subjek << " : " << valueA << " ---> " << this->object << " :"<< "B" << std::endl;
    std::cout << "B adalah" << std::endl;
    return nilaiPecah * valueA;
}

float Perbandingan::hasilBerbalikNilaiA(int valueB){
    float nilaiSatu = this->valueSubject * (float)this->valueObject;

    std::cout << this->subjek << " : " << this->valueSubject << " ---> " << this->object << " :" << this->valueObject << std::endl;
    std::cout << this->subjek << " : x" << " ---> " << this->object << " :" << valueB << std::endl;
    std::cout << "A adalah" << std::endl;
    return nilaiSatu / valueB;
}

float Perbandingan::hasilBerbalikNilaiB(int valueA){
    float nilaiSatu = this->valueSubject * (float)this->valueObject;

    std::cout << this->subjek << " : " << this->valueSubject << " ---> " << this->object << " :" << this->valueObject << std::endl;
    std::cout << this->subjek << " : x" << " ---> " << this->object << " :" << valueA << std::endl;
    std::cout << "A adalah" << std::endl;
    return nilaiSatu / valueA;
}