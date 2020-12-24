#include <iostream>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    std::cout << "Введите любое трёхзначное число " << std::endl;
    do {
        std::cin >> x;
    } while (x < 100 || x > 999);
   
    int sum = x / 100 + (x % 100) / 10 + x % 10;

    if ((sum % 3 == 0) == (x % 3 == 0)) {
        std::cout << "теорема доказана";
    }
    else {
        std::cout << "теорема не доказана";
    }


    
    system("pause");
}