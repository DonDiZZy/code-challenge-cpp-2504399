#include <iostream>

int fibonacci(int n)
{
    // todo implementieren Sie die Fibonacci Folge
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n > 1) return fibonacci(n - 1) + fibonacci(n - 2);
    return 0;
}

int main()
{

    std::cout << "n=5: " << fibonacci(5) << " -- richtiges F5 = 5" << std::endl;
    std::cout << "n=15: " << fibonacci(15) << " -- richtiges F15 = 610" << std::endl;
    return 0;
}