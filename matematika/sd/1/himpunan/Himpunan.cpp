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

void Himpunan::cetak() const {
    for (size_t i = 0; i < arryDuaDimensi.size(); ++i) {
        std::cout << "Himpunan ke-" << i << ": ";
        for (int nilai : arryDuaDimensi[i]) {
            std::cout << nilai << ' ';
        }
        std::cout << '\n';
    }
}
