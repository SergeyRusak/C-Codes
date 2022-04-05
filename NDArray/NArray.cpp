﻿// NArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "NDArray.h"
#include <iostream>

int main()
{

    std::vector<int> testsize;
    testsize.push_back(2);
    testsize.push_back(2);

    NDArray<int> test(testsize);
    test.set(0, 1);
    std::cout << test.get(0);
    NDArray<int> test2(3, 2, 2, 2);
    test2.set(0, 2);
    NDArray<int>test21(NDArray<int>::one(2,2,2));
    NDArray<int>test22 = NDArray<int>::rand(2,2,2);
    std::cout << test22.get(0) << std::endl;
    NDArray<int>test3 = test22.MatrixMultiply(test21);
    std::cout << test3[0];

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
