// hashdef.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

char hash1(char a1, char a2) {
    int hashcode = 0;
    while (a1 > 0 || a2 > 0) 
    {
        hashcode += (a1 & 1) ^ (a2 & 1);
        a1 = a1 >> 1;
        a2 = a2 >> 1;
        hashcode = hashcode << 1;
    }
    int hash = 0;
    while (hashcode > 0)
    {
        hash += hashcode & 1;
        hash = hash << 1;
        hashcode = hashcode >> 1;
    }
    return hash;
}



int main()
{
    std::string text;

    std::cin >> text;
    char hash = 0;

    for (int i = 0; i < text.size(); i++)
    {
        hash = hash1(hash, int(text[i]));
    }

    std::cout << "Your hashcode: " << hash << std::endl;


   
}
