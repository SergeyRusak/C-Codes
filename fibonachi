#include <iostream>
#include "ConsoleApplication3.h"




long long* Fib(int n) {
    long long* a = new long long[n];
    a[0] = a[1] = 1;
    int number=1;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] + a[i - 2] < INT_MAX) {
            a[i] = a[i - 1] + a[i - 2];
            number++;
        }
        else 
        {
            std::cout << "last number: " << number <<std::endl;
            break;
        }

    }
    

    return a;

}



int main()
{

    const int FIB_COUNT = 115;
    int last_num = 0;
    long long* fib_arr = Fib(FIB_COUNT);

 
        for (int i = 0; i < FIB_COUNT; i++)
        {
            if (fib_arr[i] < 0) {
                std::cout << " Too much numbers!!!";
                break;
        }
            std::cout << fib_arr[i] << " ";
        }
  
}

