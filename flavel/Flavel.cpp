// Flavel.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "ArrayList.h"


int flavel_rec(int n, int k) {
    if (n == 1) return 1;
    return (flavel_rec(n - 1, k) + k - 1) % n + 1;
}

int flavel_brute_force2(int n, int k) {
    ArrayList order(n);
    for (int i = 0; i < n; i++) 
    { 
        order.insert(i + 1);
    }
    int current = 1;
    while (order.getSize() != 1) {
        if (current == k) {
            order.remove(0);
            current = 1;
        }
        else {
            int a = order[0];
            order.remove(0);
            order.insert(a);
            current++;
        }
    }
    return order[0];

}

int flavel_brute_force(int n, int k) {
    std::vector<int> order;
    for (int i = 1; i < n+1; i++)
    {
        order.push_back(i);
    }
    int current = 1;
    while (order.size() != 1) {
        if (current == k) {
            order.erase(order.begin());
            current = 1;
        }
        else {
            int a = order[0];
            order.erase(order.begin());
            order.push_back(a);
            current++;
        }
    }
    return order[0];
}





int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "Введите количество людей. N=";
    std::cin >> n;
    std::cout << "Введите номер человека в очереди, который будет казнён." << std::endl << "(пример: N = 3; K =2) Итог: [1, (2), 3]" << std::endl << " K=";
    std::cin >> k;
    std::cout << "Идёт тестирование рекурсивной функции..." << std::endl;
    clock_t start = clock();
    int a = flavel_rec(n, k);
    clock_t end = clock();
    std::cout.setf(std::ios::fixed);
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Ответ = " << a << "  Время работы:" << std::setw(15) << std::setprecision(10) << seconds<<" секунд"<< std::endl;
    std::cout << "Идёт тестирование функции\"Перебора\"..." << std::endl;
    start = clock();
    a = flavel_brute_force(n, k);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Ответ = " << a << "  Время работы:" << std::setw(15) << std::setprecision(10)<< seconds << " секунд" << std::endl;
    std::cout << "Идёт тестирование функции\"Перебора\" с применением собственного класса ArrayList..." << std::endl;
    start = clock();
    a = flavel_brute_force2(n, k);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Ответ = " << a << "  Время работы:" << std::setw(15) << std::setprecision(10) << seconds << " секунд" << std::endl;

   





}

