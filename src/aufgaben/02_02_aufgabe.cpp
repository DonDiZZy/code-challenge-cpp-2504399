#include <iostream>
#include <vector>

namespace Calc{
    static int ProduktEx(std::vector<int> eingabe, int idx){
        int Produkt = 1;
    
        for(int i=0;i<eingabe.size();i++){
            if(i!=idx) Produkt = Produkt * eingabe[i];
        }

        return Produkt;
    }
}

int main()
{
    std::vector<int> eingabe{5, 34, 2, 8, 6, 2};

    std::cout << "Ausgabe der Produkte " << std::endl;
    for(int i=0; i<eingabe.size();i++){
        std::cout << i << "(" << eingabe.at(i) << "): " << Calc::ProduktEx(eingabe,i) << std::endl;
    }

    return 0;
}