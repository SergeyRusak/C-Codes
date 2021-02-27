#include <iostream>
#include <locale.h>


long long* Fib(int n, int *last) {
    long long* a = new long long[n];
    a[0] = a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] + a[i - 2] < INT_MAX) {
            a[i] = a[i - 1] + a[i - 2];
      
        }
        else
        {
            *last = i;
            break;
        }
        *last = -1;

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
    long long* fib_arr = Fib(FIB_COUNT, &last_num);


    for (int i = 0; i < FIB_COUNT; i++)
    {
        if (last_num > -1) {
            std::cout << "Числа не помещаются в выделенную память. Последний номер числа:"<<last_num;

            break;
        }
        std::cout << fib_arr[i] << " ";
    }

}
