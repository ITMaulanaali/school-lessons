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
    std::vector<std::vector<int>> arryUrut;
    int wadah = 0;
    int index = 0;

    int n = arryDuaDimensi.size();

    for(int baris=0; baris<n; baris++){
        wadah = arryDuaDimensi[baris].size();
        for(int barisDua=0; barisDua<arryDuaDimensi.size(); barisDua++){
            if(wadah > arryDuaDimensi[barisDua].size()){
                wadah = arryDuaDimensi[barisDua].size();
                index = barisDua;
            }
        }

        //masukan himpunan ke index terdepan
        arryUrut.push_back({});
        for(int k=0; k < arryDuaDimensi[index].size(); k++ ){
            arryUrut.back().push_back(arryDuaDimensi[index][k]);
        }
        arryDuaDimensi.erase(arryDuaDimensi.begin() + index);
    }

    std::vector<bool> hasilPerbandingan;
    for(int i=1; i<arryUrut.size(); i++){
        for(int j=0; j<arryUrut[i-1].size(); j++){
            hasilPerbandingan.push_back(false);

            for(int k=0; k<arryUrut[i].size(); k++){
                if(arryUrut[i-1][j] == arryUrut[i][k]){
                    hasilPerbandingan[j] = true;
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

            for(int k=0; k<arryUrut[i-1].size(); k++){
                std::cout << arryUrut[i-1][k];
            }
            std::cout << std::endl;
            for(int k=0; k<arryUrut[i].size(); k++){
                std::cout << arryUrut[i][k];
            }
            std::cout << std::endl;
            std::cout << "-------" << std::endl;
        }
        hasilPerbandingan.clear();
    }
}

void Himpunan::cetak() const {
    for (size_t i = 0; i < arryDuaDimensi.size(); ++i) {
        std::cout << "Himpunan ke-" << i << ": ";
        for (int nilai : arryDuaDimensi[i]) {
            std::cout << nilai << ' ';
        }
        std::cout << '\n';
    }
}