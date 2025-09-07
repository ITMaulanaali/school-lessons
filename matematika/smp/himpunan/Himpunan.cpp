#include "Himpunan.hpp"

template<typename T, typename... Args>
void Himpunan::inputCollection(T bilPertama, Args... data) {
    if(bilPertama == 0) {
        baris++;
        return;
    }else if(baris > barisSebelumnya) {
        barisSebelumnya++;
        arryDuaDimensi.push_back({});
    }
        
    arryDuaDimensi[baris].push_back(bilPertama);

    if constexpr (sizeof...(data) > 0) {
        inputCollection(data...);
    }else{
        inputCollection(0);
    }
}

void Himpunan::himpunanBagian(){
    std::vector<std::vector<int>> cloneArryDuaDimensi = this->arryDuaDimensi;
    std::vector<std::vector<int>> arryUrut;
    int wadah = 0;
    int index = 0;

    for(int baris=0; !cloneArryDuaDimensi.empty(); baris++){
        wadah = cloneArryDuaDimensi[0].size();
        index = 0;
        for(int barisDua=0; barisDua<cloneArryDuaDimensi.size(); barisDua++){
            if(wadah > cloneArryDuaDimensi[barisDua].size()){
                wadah = cloneArryDuaDimensi[barisDua].size();
                index = barisDua;
            }
        }

        //masukan himpunan ke index terdepan
        arryUrut.push_back({});
        for(int k=0; k < cloneArryDuaDimensi[index].size(); k++ ){
            arryUrut.back().push_back(cloneArryDuaDimensi[index][k]);
        }
        cloneArryDuaDimensi.erase(cloneArryDuaDimensi.begin() + index);
    }

    std::vector<bool> hasilPerbandingan;
    for(int i=0; i<arryUrut.size(); i++){
        for(int j=0; j<arryUrut.size(); j++){
            if(i==j) continue;

            for(int k=0; k<arryUrut[i].size(); k++){
                hasilPerbandingan.push_back(false);
                for(int l=0; l<arryUrut[j].size(); l++){
                    if(arryUrut[i][k] == arryUrut[j][l]){
                        hasilPerbandingan[k] = true;
                        break;
                    }
                }
            }
        

            //mengecek hasilPerbandingan
            bool perbandinganSamaSemua = true;
            for(int j=0; j<hasilPerbandingan.size(); j++){
                if(!hasilPerbandingan[j]){
                    perbandinganSamaSemua = false;
                    break;
                }
            }

            if(perbandinganSamaSemua){
                std::cout << "Merupakan himpunan bagian" << std::endl;

                for(int k=0; k<arryUrut[i].size(); k++){
                    std::cout << arryUrut[i][k];
                }
                std::cout << std::endl;
                for(int k=0; k<arryUrut[j].size(); k++){
                    std::cout << arryUrut[j][k];
                }
                std::cout << std::endl;
                std::cout << "-------" << std::endl;
            }
            hasilPerbandingan.clear();
        }
    }
}

void Himpunan::himpunanIrisan(){
    std::vector<std::vector<int>> cloneArryDuaDimensi = this->arryDuaDimensi;
    std::vector<std::vector<int>> arryIrisan;
    int irisan=0;

    int duplikatValue;
    for(int i=0; i<cloneArryDuaDimensi.size(); i++){
        for(int j=0; j<cloneArryDuaDimensi[i].size(); j++){
            duplikatValue = cloneArryDuaDimensi[i][j];
            for(int k=j+1; k<cloneArryDuaDimensi[i].size(); k++){
                if(duplikatValue == cloneArryDuaDimensi[i][k]){
                    cloneArryDuaDimensi[i].erase(cloneArryDuaDimensi[i].begin() + k);
                    k--;
                }
            }
        }

        arryIrisan.push_back(cloneArryDuaDimensi[i]);
    }

    for(int i=0; i<arryIrisan.size(); i++){
        for(int j=i+1; j<arryIrisan.size(); j++){
            for(int x:arryIrisan[i]){
                std::cout << x << " ";
            }
            std::cout << std::endl;
            for(int x:arryIrisan[j]){
                std::cout << x << " ";
            }
            std::cout << std::endl;
            std::cout << "Memiliki himpunan irisan:" << std::endl;
            //mencari himpunan irisan
            for(int k=0; k<arryIrisan[i].size(); k++){
                for(int l=0; l<arryIrisan[j].size(); l++){
                    if(arryIrisan[i][k] == arryIrisan[j][l]){
                        irisan++;
                        // std::cout << arryIrisan[i][k];
                        // break;
                    }
                }

                for(int l=0; l<arryIrisan[j].size(); l++){
                    if(arryIrisan[i][k] == arryIrisan[j][l]){
                        if(irisan < arryIrisan[i].size() && irisan < arryIrisan[j].size()){
                            std::cout << arryIrisan[i][k] << " ";
                            break;
                        }
                    }
                }
            }
            irisan=0;
            std::cout << std::endl;
            std::cout << "--------" << std::endl;
        }
    }
}

void Himpunan::himpunanGabungan(){
    std::vector<std::vector<int>> cloneArryDuaDimensi = this->arryDuaDimensi;
    std::vector<std::vector<int>> arryGabungan;
    int indexGabungan=0;

    for(int i=0; i<cloneArryDuaDimensi.size(); i++){
        for(int j=i+1; j<cloneArryDuaDimensi.size(); j++){
            arryGabungan.push_back({});
            indexGabungan = arryGabungan.size() - 1;
            for(int k=0; k<cloneArryDuaDimensi[i].size(); k++){
                arryGabungan[indexGabungan].push_back(cloneArryDuaDimensi[i][k]);
            }
            for(int k=0; k<cloneArryDuaDimensi[j].size(); k++){
                arryGabungan[indexGabungan].push_back(cloneArryDuaDimensi[j][k]);
            }
        }
    }

    //mengatur nilai dalam satu baris arry tidak ada yang sama
    for(int i=0; i<arryGabungan.size(); i++){
        for(int j=0; j<arryGabungan[i].size(); j++){
            for(int k=j+1; k<arryGabungan[i].size(); k++){
                if(arryGabungan[i][j] == arryGabungan[i][k]){
                    arryGabungan[i].erase(arryGabungan[i].begin() + k);
                    k--;
                }
            }
        }
    }

    //menampilkan himpunan bagian
    indexGabungan=0;
    for(int i=0; i<cloneArryDuaDimensi.size(); i++){
        for(int j=i+1; j<cloneArryDuaDimensi.size(); j++){
            
            for(int k=0; k<cloneArryDuaDimensi[i].size(); k++){
                std::cout << cloneArryDuaDimensi[i][k] << " ";
            }
            std::cout << std::endl;
            for(int k=0; k<cloneArryDuaDimensi[j].size(); k++){
                std::cout << cloneArryDuaDimensi[j][k] << " ";
            }
            std::cout << std::endl;
            std::cout << "--------" << std::endl;
            
            for(int k=0; k<arryGabungan[indexGabungan].size(); k++){
                std::cout << arryGabungan[indexGabungan][k] << " ";
            }
            std::cout << std::endl << std::endl;
            indexGabungan++;
        }
    }
}

void Himpunan::himpunanKomplemen(int x){
    std::vector<std::vector<int>> cloneArryDuaDimensi = this->arryDuaDimensi;
    std::vector<int> arrySatuD;
    std::vector<int> arrySatuDKomplemen;
    /*
        1. simpan tiap datum baris index x atau komplemen x pada arraySatuD
        2. loop atau tampilkan semua data kecuali data yang memiliki nilai sama dengan yang ada di x (hapus)
    */

    //menyimpan nilai bukan kompelemen dari x to arrySatuD
    for(int i=0; i<cloneArryDuaDimensi.size(); i++){
        if(i!=x-1) continue;
        for(int j=0; j<cloneArryDuaDimensi[i].size(); j++){
            arrySatuD.push_back(cloneArryDuaDimensi[i][j]);
        }
    }

    //simpan komplemen dari x ke arrySatuDKomplemen
    for(int i=0; i<cloneArryDuaDimensi.size(); i++){
        if(i==x-1) continue;
        for(int j=0; j<cloneArryDuaDimensi[i].size(); j++){
            arrySatuDKomplemen.push_back(cloneArryDuaDimensi[i][j]);
        }
    }

    //cek nilai yang sama di arraySatuD dengan ArraySatuDKompelen, Jika sama hapus
    for(int i=0; i<arrySatuD.size(); i++){
        for(int j=0; j<arrySatuDKomplemen.size(); j++){
            if(arrySatuD[i] == arrySatuDKomplemen[j]){
                arrySatuDKomplemen.erase(arrySatuDKomplemen.begin() + j);
                j--;
            }
        }
    }

    //hapus nilai yang sama di arrySatuKomplemen itu sendiri
    for(int i=0; i<arrySatuDKomplemen.size(); i++){
        for(int j=i+1; j<arrySatuDKomplemen.size(); j++){
            if(arrySatuDKomplemen[i] == arrySatuDKomplemen[j]){
                arrySatuDKomplemen.erase(arrySatuDKomplemen.begin() + j);
                j--;
            }
        }
    }

    std::cout << "Kompelemen dari baris: "  << x << " adalah: " << std::endl;
    cetak(arrySatuDKomplemen);
}

void Himpunan::cetak(std::vector<std::vector<int>> arry) const {
    for (size_t i = 0; i < arry.size(); ++i) {
        std::cout << "Himpunan ke-" << i << ": ";
        for (int nilai : arry[i]) {
            std::cout << nilai << ' ';
        }
        std::cout << '\n';
    }
}

void Himpunan::himpunanKuasa(int x){
    x = x-1;
    int nKolom = 0;
    int hasilKuasa = 2;

    std::cout << "Himpunan kuasa dari: ";
    for(int i=0; i<this->arryDuaDimensi[x].size(); i++){
        std::cout << this->arryDuaDimensi[x][i] << " ";
        nKolom++;
    }
    std::cout << std::endl;

    for(int i=1; i<nKolom; i++){
        hasilKuasa = 2*hasilKuasa;
    }

    std::cout << hasilKuasa << std::endl;

}

void Himpunan::totalSemesta(){
    int total=0;

    for(int i=0; i<this->arryDuaDimensi.size(); i++){
        for(int j=0; j<this->arryDuaDimensi[i].size(); j++){
            total++;
        }
    }

    std::cout << "Total himpunan semesta: " << total << std::endl;
}

void Himpunan::cetak(std::vector<int> arr) const {
    std::cout << "Himpunan: ";
    for (int nilai : arr) {
        std::cout << nilai << ' ';
    }
    std::cout << '\n';
}


