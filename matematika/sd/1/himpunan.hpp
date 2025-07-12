#include <vector>
#include <iostream>

class himpunan {
private:
    std::vector<std::vector<int>> arryDuaDimensi;
    short baris = 0;
    short barisSebelumnya = -1;

public:
    template<typename T, typename... Args>
    void inputCollection(T bilPertama, Args... data) {
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

    void himpunanBagian(){
        std::vector<std::vector<int>> arryUrut;
        int wadah;
        int index;

        for(int baris=0; baris<arryDuaDimensi.size(); baris++){
            wadah = arryDuaDimensi[baris].size();
            for(int barisDua=0; barisDua<arryDuaDimensi.size(); barisDua++){
                if(wadah > arryDuaDimensi[barisDua].size()){
                    wadah = arryDuaDimensi[barisDua].size();
                    index = barisDua;
                }
            }

            //masukan himpunan ke index terdepan
            for(int k=0; k < arryDuaDimensi[index].size(); k++ ){
                arryUrut[baris].push_back(arryDuaDimensi[index][k]);
            }
            arryDuaDimensi.erase(arryDuaDimensi.begin() + index);
        }
    }

    void cetak() const {
    for (size_t i = 0; i < arryDuaDimensi.size(); ++i) {
        std::cout << "Himpunan ke-" << i << ": ";
        for (int nilai : arryDuaDimensi[i]) {
            std::cout << nilai << ' ';
        }
        std::cout << '\n';
    }
}
};
 