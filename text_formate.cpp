#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

std::string formate(std::string line, int format, int max_lenght) {
    int free_space = max_lenght - line.length();


    switch (format)
    {
    case 0:  //Formating.left
        for (int i = 0; i < free_space; i++)
        {
            line.append(" ");

        }



        break;
    case 1:  //Formating.center
        for (int i = 0; i < free_space; i++)
        {
            if (i % 2 == 0) line.insert(0, " ");
            else line.append(" ");

        }



        break;
    case 2:  //Formating.right
        for (int i = 0; i < free_space; i++)
        {
            line.insert(0, " ");

        }
        break;
    case 3:  //Formating.width
    {
        int space_count = 0;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') space_count++;
        }   
        int space_width =(space_count!=0)?( free_space / space_count):(0);
        std::string space = "";
        
        for (int i = 0; i < space_width; i++) {
            space.append(" ");
        }
        
        for (int i = 0; i < line.length(); i++) {
            
            if (line[i] == ' ') {
                line.insert(i, space);
                i += space_width;
                
            }          
        }

        int last_space = free_space - (space_count * space_width);
        for (int i = 0; i < line.length()-1; i++) {
            if (line[i] == ' ' && line[i + 1] != ' ') 
            {
                line.insert(i, " ");
                i++;
                last_space--;
                if (last_space == 0) break;
            }

        }


        break;
    }


    default:
        break;
    }
    return line;


}

std::string clearSpace(std::string line) {
    for (int i = line.length() - 1; i >= 0; i--)
    {
        if (line[i] == ' ') {
            if (i == 0 || i == line.length() - 1) line.erase(i,1);
            else if (line[i - 1] == ' ') line.erase(i,1);
            else if (line[i + 1] == '.' || line[i + 1] == ',' || line[i + 1] == '!' || line[i + 1] == '?') line.erase(i);
        }

    }
    return line;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int text_COUNT;
    unsigned int MAX_LENGHT = 80;

    std::cout << "Введите количество строк в тексте:";
    std::cin >> text_COUNT;
    std::string* text = new std::string[text_COUNT];

    std::cout << "Введите текст" << std::endl;
    std::cout << "ВНИМАНИЕ! Все символы, не поместившиеся в диапозон " << MAX_LENGHT << "-и символов будут удаляться!" << std::endl;
    for (int i = 0; i < text_COUNT; i++) {

        std::getline(std::cin, text[i]);

        while (text[i].length() ==0) std::getline(std::cin, text[i]);

        if (text[i].length() > MAX_LENGHT) {
            text[i].erase(MAX_LENGHT, text[i].length() - MAX_LENGHT);
        }
    }
    std::cout << "Доступные типы выравнивания:" << std::endl;
    std::cout << "0 -  выравнивание по правому краю;" << std::endl;
    std::cout << "1 -  выравнивание по центру;" << std::endl;
    std::cout << "2 -  выравнивание по левому краю;" << std::endl;
    std::cout << "3 -  выравнивание по ширине строки." << std::endl;
    std::cout << "Введите тип выравнивания:";
    int tf;
    std::cin >> tf;

    for (int i = 0; i < text_COUNT; i++)
    {
        text[i] = formate(clearSpace(text[i]), tf, MAX_LENGHT);

    }

    for (int i = 0; i < text_COUNT; i++)
    {
        std::cout << text[i] << std::endl;


    }




}
