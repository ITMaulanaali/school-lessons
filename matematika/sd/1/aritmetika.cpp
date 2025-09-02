#include <vector>
#include <iostream>
#include <string>
#include <sstream>

/*
sudah memenuhi
- bilangan identitas
- asosiatif
- komutatif
*/
int tambah(int bil1, int bil2){
    return bil1 + bil2;
}

int kurang(int bil1, int bil2){
    return bil1 - bil2;
}

int kali(int bil1, int bil2){
    return bil1 * bil2;
}

double pangkat(int bilangan, int pangkat){
    double hasil = bilangan;
    for(double i=1; i<pangkat; i++){
        hasil = bilangan * hasil;
    }
    return hasil;
}

std::string prima(int bilPrima){
    std::string hasil = "";

    if(bilPrima == 0){
        hasil = "x0";
    }else if(bilPrima == 1){
        hasil = "x1";
    }

    while(bilPrima != 1){
        if (bilPrima % 2 == 0) {
    hasil += "x2";
    bilPrima = bilPrima / 2;
} else if (bilPrima % 3 == 0) {
    hasil += "x3";
    bilPrima = bilPrima / 3;
} else if (bilPrima % 5 == 0) {
    hasil += "x5";
    bilPrima = bilPrima / 5;
} else if (bilPrima % 7 == 0) {
    hasil += "x7";
    bilPrima = bilPrima / 7;
} else if (bilPrima % 11 == 0) {
    hasil += "x11";
    bilPrima = bilPrima / 11;
} else if (bilPrima % 13 == 0) {
    hasil += "x13";
    bilPrima = bilPrima / 13;
} else if (bilPrima % 17 == 0) {
    hasil += "x17";
    bilPrima = bilPrima / 17;
} else if (bilPrima % 19 == 0) {
    hasil += "x19";
    bilPrima = bilPrima / 19;
} else if (bilPrima % 23 == 0) {
    hasil += "x23";
    bilPrima = bilPrima / 23;
} else if (bilPrima % 29 == 0) {
    hasil += "x29";
    bilPrima = bilPrima / 29;
} else if (bilPrima % 31 == 0) {
    hasil += "x31";
    bilPrima = bilPrima / 31;
} else if (bilPrima % 37 == 0) {
    hasil += "x37";
    bilPrima = bilPrima / 37;
} else if (bilPrima % 41 == 0) {
    hasil += "x41";
    bilPrima = bilPrima / 41;
} else if (bilPrima % 43 == 0) {
    hasil += "x43";
    bilPrima = bilPrima / 43;
} else if (bilPrima % 47 == 0) {
    hasil += "x47";
    bilPrima = bilPrima / 47;
} else if (bilPrima % 53 == 0) {
    hasil += "x53";
    bilPrima = bilPrima / 53;
} else if (bilPrima % 59 == 0) {
    hasil += "x59";
    bilPrima = bilPrima / 59;
} else if (bilPrima % 61 == 0) {
    hasil += "x61";
    bilPrima = bilPrima / 61;
} else if (bilPrima % 67 == 0) {
    hasil += "x67";
    bilPrima = bilPrima / 67;
} else if (bilPrima % 71 == 0) {
    hasil += "x71";
    bilPrima = bilPrima / 71;
} else if (bilPrima % 73 == 0) {
    hasil += "x73";
    bilPrima = bilPrima / 73;
} else if (bilPrima % 79 == 0) {
    hasil += "x79";
    bilPrima = bilPrima / 79;
} else if (bilPrima % 83 == 0) {
    hasil += "x83";
    bilPrima = bilPrima / 83;
} else if (bilPrima % 89 == 0) {
    hasil += "x89";
    bilPrima = bilPrima / 89;
} else if (bilPrima % 97 == 0) {
    hasil += "x97";
    bilPrima = bilPrima / 97;
}

    }
    hasil.erase(0,1);
    return hasil;
}

std::string fpb(std::string primaSatu, std::string primaDua){
    std::vector<int> komparasiSatu;
    std::vector<int> komparasiDua;
    std::vector<int> hasilFpb;
    std::stringstream prima1(primaSatu);
    std::stringstream prima2(primaDua);

    std::string character = "";
    while(std::getline(prima1, character, 'x')){
        komparasiSatu.push_back(std::stoi(character));
    }

    while(std::getline(prima2, character, 'x')){
        komparasiDua.push_back(std::stoi(character));
    }
    
    for(size_t i=0; i<komparasiSatu.size(); i++){
        for(size_t j=0; j<komparasiDua.size(); j++){
            if(komparasiSatu[i] == komparasiDua[j]){
                hasilFpb.push_back(komparasiSatu[i]);
                komparasiDua.erase(komparasiDua.begin());
                break;
            }
        }
    }
    
    std::string allResults;
    for(size_t i=0; i<hasilFpb.size(); i++){
        allResults += std::to_string(hasilFpb[i]) + "x";
    }
    allResults.pop_back();

    return allResults;
}

int kpk(int bil1, int bil2){
    std::vector<int> kelipatanBil1;
    std::vector<int> kelipatanBil2;
    kelipatanBil1.push_back(bil1);
    kelipatanBil2.push_back(bil2);
    int hasilKpk;

    int loop = 1;
    bool stopIterasi = true;
    while(stopIterasi){
        kelipatanBil1.push_back(bil1 * (loop+1));
        kelipatanBil2.push_back(bil2 * (loop+2));
        
        for(size_t i=0; i<kelipatanBil1.size(); i++){
            for(size_t j=0; j<kelipatanBil2.size(); j++){
                if(kelipatanBil1[i] == kelipatanBil2[j]){
                    hasilKpk = kelipatanBil1[i];
                    stopIterasi = false;
                }
            }
        }
        loop++;
    }
    return hasilKpk;
}

float sederhanakanPecahan(int pembilang, int penyebut){
    std::string stringNilaiFpb = fpb(prima(pembilang),prima(penyebut));
    int nilaiFpb = 1;
    float hasilPecahanDesimal;

    std::stringstream ss(stringNilaiFpb);
    std::string token;
    while (std::getline(ss, token, 'x')) {
    if (!token.empty()) {
        nilaiFpb *= std::stoi(token);  // pastikan token valid angka
    }
    }

    // nilaiFpb *= std::stoi(std::string(1,stringNilaiFpb[stringNilaiFpb.size()-1]));

    pembilang = pembilang/nilaiFpb;
    penyebut = penyebut/nilaiFpb;

    hasilPecahanDesimal = (float)pembilang / (float)penyebut;
    return hasilPecahanDesimal;
}