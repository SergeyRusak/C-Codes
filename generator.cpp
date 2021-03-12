#include <iostream>
#include <ctime>
#include <locale.h>


long long* GenerateArray(int N, long long begin, long long end ) {
    srand(time(0));

    long long* arr = new long long[N];

    for (int i = 0; i < N; i++) {
        arr[i] = (long long)rand() % (end - begin + 1 ) + begin;
    }
          


    return arr;
}


void scatter(long long* arr, int size)
{
    srand(time(0));
    long long temp;
    int swit;
    for (int i = 0; i < size; i++)
    {
        swit = rand() % (size - 1);
        temp = arr[swit];
        arr[swit] = arr[i];
        arr[i] = temp;
    }

}


long long* GenerateNonCopyArray(int N, long long begin, long long end) {
    srand(time(0));

    long long* arr = new long long[N];

    long long g = (end - begin) / N;


    long long beginS = begin;
    for (int i = 0; i < N; i++) {

         end = beginS + g * (i + 1);
         long long genered = (long long)rand() % (end - begin + 1) + begin;
         begin = genered + 1;


         arr[i] = genered;
    }

    scatter(arr, N);

    return arr;
}






int main()
{



    setlocale(LC_ALL, "Russian");
    int N, begin, end;
    std::cout << "Введите количество элементов и их диапозон :";

    std::cin >> N >> begin >> end;
    while ((end - begin) < N) std::cin >> begin >> end;





    long long* a = GenerateNonCopyArray(N, begin, end);
    
    for (int i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }




}
