#include <iostream>

double exponentFunktion(int basis, int exponent)
{
    int exponentwert = 1;
    int ungerade = 1;

    if(exponent == 0) return 1;
    if(exponent == 1) return basis;
    if(exponent == 2) return basis * basis;
    if(exponent%2==1){
        exponent--;
        ungerade = basis;
    }
    exponentwert *= exponentFunktion(basis,exponent/2);
    exponentwert *= exponentwert * ungerade;

    return exponentwert;
}

int main()
{
    std::cout << "5^8: " << exponentFunktion(5, 8) << " -- richtiges Ergebnis 390625" << std::endl;
    std::cout << "9^3: " << exponentFunktion(9, 3) << " -- richtiges Ergebnis 729" << std::endl;
    return 0;
}