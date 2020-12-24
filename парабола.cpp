#include <iostream>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");

    float a, b, c;
    float x, y;
    std::cout << "Введите постоянные A,B и C квадратного уравнения (y=ax^2+bx+c)" << std::endl;
    do {
        std::cin >> a;
    } while (a == 0);
    std::cin >> b >> c;
    x = -b / 2 / a;
    y = a * x * x + b * x + c;
    std::cout <<"вершина параболы - (" << x <<":" << y<<")" << std::endl;
    system("pause");
}
