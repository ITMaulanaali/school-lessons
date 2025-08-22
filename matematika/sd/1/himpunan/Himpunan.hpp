#ifndef __Himpunan
#define __Himpunan

#include <vector>
#include <iostream>

class Himpunan {
    private:
        std::vector<std::vector<int>> arryDuaDimensi;
        short baris = 0;
        short barisSebelumnya = -1;

    public:
        template<typename T, typename... Args>
        void inputCollection(T bilPertama, Args... data);

        void himpunanBagian();
        void himpunanIrisan();
        void cetak() const;
};

#endif