#include <iostream>
#include <locale.h>

void hanoi(int N, int main, int sec, int goal) {
    if (N == 2) {
        std::cout << main << " -> " << sec << std::endl;
        std::cout << main << " -> " << goal << std::endl;
        std::cout << sec << " -> " << goal << std::endl;
    }
    else {
        hanoi(N - 1, main, goal, sec);
        std::cout << main << " -> " << goal << std::endl;
        hanoi(N - 1, sec, main, goal);
    }
}

void hanoi(int N) {
    hanoi(N, 1, 2, 3);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите количество блинов на первой башне: ";
    std::cin >> N;
    hanoi(N);
 }
