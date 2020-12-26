// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <string>


void simulate(int a[], int height_modify, int end_sim_time, int task_number) {
    
    int m[25];
    for (int i = 0; i < 25; i++)
    {
        m[i] = a[i];
    }

    bool any_changes = false;
    int prev_modify = 0;
    int min = 0;
    while (true)
    {
        min++;
        std::cout << m[0] << " ";
        for (int i = 1; i < 24; i++)
        {
            if (m[i - 1]<m[i] && m[i]>m[i + 1]) {
                any_changes = true;
                m[i - 1]= (m[i - 1]+prev_modify <0)?(0):(m[i - 1] + prev_modify);
                prev_modify = -height_modify;
            }
            else
                if (m[i - 1]<m[i] && m[i]>m[i + 1]) {
                    any_changes = true;
                    m[i - 1] = (m[i - 1] + prev_modify < 0) ? (0) : (m[i - 1] + prev_modify);
                    prev_modify = height_modify;
                }
                else {
                    m[i - 1] = (m[i - 1] + prev_modify < 0) ? (0) : (m[i - 1] + prev_modify);
                }
            std::cout << m[i] << " ";
        }
        m[23] = (m[23] + prev_modify < 0) ? (0) : (m[23] + prev_modify);
        std::cout << m[24] << std::endl;
        if (!any_changes || min >= end_sim_time) break;
        any_changes = false;
        prev_modify = 0;
    }

    if (!any_changes) {
        std::cout << "Задача №"<<task_number << std::endl << "Прошло времени:" << min << " минут" << std::endl << "Дальнейшие изменения не наблюдаются" << std::endl;
    }
    if (min >=end_sim_time) {
        std::cout << "Задача №"<<task_number << std::endl << "Симуляция была прервана без получения положительного результвата по причине нехватки времени!" << std::endl << "Увеличьте временной диапазон или измените другие параметры!" << std::endl;
    }

}

int main()
{

    const int END_SIMULATION_TIME = 30000;


    setlocale(LC_ALL, "Russian");
    int m[25];
    std::cout << "Введите 25 натуральных чисел, которые соответствуют росту в сантиметрах:"<<std::endl;
    for (int i = 0; i < 25; i++)
    {
        do {
            std::cin >> m[i];
        } while (m[i] <= 0);
    }
    simulate(m, 1, END_SIMULATION_TIME, 1);
    system("pause");
    simulate(m, 2, END_SIMULATION_TIME, 2);
   
 


    system("pause");
    }  
      