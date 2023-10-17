#include <iostream>
#include <vector>
#include <map>

namespace Calc{
    template<typename T>
    static T Volumen(T a, T b){
        return a * b;
    }
    template<typename T>
    static T Max(T a, T b){
        if(a>b) return a;
        return b;
    }
    template<typename T>
    static T Min(T a, T b){
        if(a<b) return a;
        return b;
    }
};

int berechneVolumen(std::vector<int> eingabe)
{
    // todo berechne Volumen
    int MaxVolumen = 0;
    
    for(std::vector<int>::iterator it = eingabe.begin();it!=eingabe.end();++it){
        int Volumen = 0, b=0;
        std::vector<int>::iterator it2 = it;
        for (; it2 != eingabe.end(); ++it2,b++){
            int a = Calc::Min(*it,*it2);
            Volumen = Calc::Volumen(a,b);
            if(Volumen>MaxVolumen) MaxVolumen=Volumen;    
        }
    }
    return MaxVolumen;
}

int main()
{
    std::vector<int> eingabe_1{8, 3, 7, 9, 3, 2, 5, 7, 2, 3, 4};       // erwarteter output 49
    std::vector<int> eingabe_2{1, 1};                                  // erwarteter output 1
    std::vector<int> eingabe_3{8, 6, 2, 5, 4, 8, 3, 7, 9, 3, 2, 5, 7}; // erwarteter output 84

    std::cout << "Max Volumen eingabe 1 " << berechneVolumen(eingabe_1) << std::endl;
    std::cout << "Max Volumen eingabe 2 " << berechneVolumen(eingabe_2) << std::endl;
    std::cout << "Max Volumen eingabe 3 " << berechneVolumen(eingabe_3) << std::endl;

    return 0;
}