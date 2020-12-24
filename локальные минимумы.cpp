#include <iostream>
#include <locale.h>
#include<iomanip>
#include <string>


int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите размер массива " << std::endl;
    do {
        std::cin >> N;
    } while (N < 1);

    float a, b, c;
    std::string output;
    std::cout << "Введите значения массива " << std::endl;
    if (N == 1) {
        std::cin >> a;
        std::cout << "0" << std::endl;
    }
    if (N == 2) {
        std::cin >> a >>b;
        if (a>b)    std::cout << "0" << std::endl;
        else        std::cout << "1" << std::endl;
    }
    if (N > 2) {
        std::cin >> a;
        std::cin >> b;
        for (int i = 1; i < N; i++) {
            std::cin >> c;
            if (a<b && b>c) output += std::to_string(i) + " ";
            a = b;
            b = c;
        }
        std::cout <<"Локальные минимумы:"<< output << std::endl;
    }  
      

    
    system("pause");
}