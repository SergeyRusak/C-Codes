#include <iostream>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");

    float ab, bb, cb, ah, bh;
    std::cout << "Введите размеры A,B и C сторон кирпича " << std::endl;
    do {
        std::cin >> ab;
    } while (ab <= 0);
    do {
        std::cin >> bb;
    } while (bb <= 0);
    do {
        std::cin >> cb;
    } while (cb <= 0);
    if (ab > bb) {
        if (cb < ab) {
            ab = cb;
        }
    }
    else {
        if (cb < bb) {
            bb = cb;
            }
    }
    std::cout << "Введите размеры A,B сторон отверстия " << std::endl;
    do {
        std::cin >> ah;
    } while (ah <= 0);
    do {
        std::cin >> bh;
    } while (bh <= 0);

    if ((ah >= ab && bh >= bb) || (bh >= ab && ah >= bb)) {
        std::cout << "Данный кирпич проходит" << std::endl;
    }
    else {
        std::cout << "Данный кирпич не проходит" << std::endl;
    }
    system("pause");
}