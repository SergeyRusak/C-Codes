#include <iostream>
#include <locale.h>
#include <iomanip>


int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "введите размер массива " << std::endl;
    do {
        std::cin >> N;
    } while (N < 1);

    float* A = new float[N];
    std::cout << "Введите значения массива " << std::endl;
    std::cin >> A[0];
    for (int i = 1; i < N; i++)
    {
        std::cin >> A[i];
        A[i] = (A[i - 1] * i + A[i]) / (i + 1);
    }
  
    std::cout << "Полученный массив:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout <<std::setprecision(3)<< A[i] << " ";
    }

  
    

    
    system("pause");
}
