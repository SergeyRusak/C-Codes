#include <iostream>
#include <locale.h>
#include <climits>

long long* Fib(int &n) {
    long long* a = new long long[n];
    a[0] = a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] < INT_MAX - a[i - 2]) {
            a[i] = a[i - 1] + a[i - 2];

        }
        else
        {
            n = -i;
            break;
        }
        

    }


    return a;

}



int main()
{

    setlocale(LC_ALL, "Russian");
    int FIB_COUNT;
    std::cout << "Введите количество чисел :";
    std::cin >> FIB_COUNT;


    int last_num = 0;
    long long* fib_arr = Fib(FIB_COUNT);

    if (FIB_COUNT < 0) {
        std::cout << "Числа не помещаются в выделенную память. Последний номер числа:" << -FIB_COUNT;
    }
    else
    {
        for (int i = 0; i < FIB_COUNT; i++)
        {
            std::cout << fib_arr[i] << " ";
        }
    }

}
