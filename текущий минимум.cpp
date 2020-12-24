
#include <iostream>
#include <locale.h>
#include<iomanip>


int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите размер массива " << std::endl;
    do {
        std::cin >> N;
    } while (N < 1);

    float* A = new float[N];
    std::cout << "Введите значения массива " << std::endl;
    float min,temp;
    std::cin >> min;
    A[0] = min;
    for (int i = 1; i < N; i++)
    {
        std::cin >> temp;
        if (temp < min)min = temp;
        A[i] = min;
        
    }
  
    std::cout << "Полученный массив:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout <<std::setprecision(3)<< A[i] << " ";
    }

  
    

    
    system("pause");
}
