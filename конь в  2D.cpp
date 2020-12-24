#include <iostream>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");

    int x, y;
    std::cout << "Введите координаты коня (x,y) " << std::endl;
    do {
        std::cin >> x;
    } while (x < 1 || x > 8);
    do {
        std::cin >> y;
    } while (y < 1 || y > 8);
    std::cout << "Возможные ходы: " << std::endl;
    if (x + 2 <= 8 && y + 1 <= 8) std::cout << "(" << x + 2 << ":" << y + 1 << ")" << std::endl;
    if (x + 2 <= 8 && y - 1 >= 1) std::cout << "(" << x + 2 << ":" << y - 1 << ")" << std::endl;
    if (x - 2 >= 1 && y + 1 <= 8) std::cout << "(" << x - 2 << ":" << y + 1 << ")" << std::endl;
    if (x - 2 >= 1 && y - 1 >= 1) std::cout << "(" << x - 2 << ":" << y - 1 << ")" << std::endl;
    if (x + 1 <= 8 && y + 2 <= 8) std::cout << "(" << x + 1 << ":" << y + 2 << ")" << std::endl;
    if (x - 1 <= 8 && y + 2 <= 8) std::cout << "(" << x - 1 << ":" << y + 2 << ")" << std::endl;
    if (x + 1 <= 8 && y - 2 >= 1) std::cout << "(" << x + 1 << ":" << y - 2 << ")" << std::endl;
    if (x - 1 >= 1 && y - 2 >= 1) std::cout << "(" << x - 1 << ":" << y - 2 << ")" << std::endl;


    
    system("pause");
}