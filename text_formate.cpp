#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>







std::string FormateLeft (std::string line, int max_lenght) 
{
    int free_space = max_lenght - line.length();
    for (int i = 0; i < free_space; i++)
    {
        line.append(" ");

    }
    return line;
}
std::string FormateRight (std::string line, int max_lenght) 
{
    int free_space = max_lenght - line.length();
    for (int i = 0; i < free_space; i++)
    {
        line.insert(0, " ");

    }

    return line;
}
std::string FormateCenter(std::string line, int max_lenght)
{

    int free_space = max_lenght - line.length();
    for (int i = 0; i < free_space; i++)
    {
        if (i % 2 == 0) line.insert(0, " ");
        else line.append(" ");

    }

    return line;
}
std::string FormateWidth (std::string line, int max_lenght)
{
    int free_space = max_lenght - line.length();
    int space_count = 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') space_count++;
    }
    int space_width = (space_count != 0) ? (free_space / space_count) : (0);
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
    for (int i = 0; i < line.length() - 1; i++) {
        if (line[i] == ' ' && line[i + 1] != ' ')
        {
            line.insert(i, " ");
            i++;
            last_space--;
            if (last_space == 0) break;
        }

    }

    return line;
}



std::string ClearSpace(std::string line) {
    for (int i = line.length() - 1; i >= 0; i--)
    {
        if (line[i] == ' ') {
            if (i == 0 || i == line.length() - 1) line.erase(i, 1);
            else if (line[i - 1] == ' ') line.erase(i, 1);
            else if (line[i + 1] == '.' || line[i + 1] == ',' || line[i + 1] == '!' || line[i + 1] == '?') line.erase(i);
        }

    }
    return line;
}
std::string Formate(std::string line, int format, int max_lenght) {    
    switch (format)
    {
    case 0:  //Formating.left
        line = FormateLeft(ClearSpace(line), max_lenght);
        break;
    case 1:  //Formating.center
        line = FormateCenter(ClearSpace(line), max_lenght);
        break;
    case 2:  //Formating.right
        line = FormateRight(ClearSpace(line), max_lenght);
        break;
    case 3:  //Formating.width
        line = FormateWidth(ClearSpace(line), max_lenght);
        break;
    default:
        break;
    }

    return line;
}
int Formating(std::string* lines, int size, std::string format_code, int max_lenght ) {
  
    
    for (int i = 0; i < format_code.length(); i++)
    {

        if (format_code[i] != '0' && format_code[i] != '1' && format_code[i] != '2' && format_code[i] != '3' && format_code[i] != '4') return -1;
            
    }
    
    if (format_code[0] == '4') {
        format_code.erase();
        
        int i = 0;
        int ix = 1;
        for (int j = 0; j < size; j++)
        {
            format_code += std::to_string(i);
            i += ix;
           
            if ((i == 2) || (i == 0)) {

                ix *= -1;
          
            }
         

        }

    }
    if (format_code.length() < size) {
        for (int i = format_code.length() - 1; i < size; i++) {
            format_code = format_code + format_code[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        lines[i] = Formate(lines[i],format_code[i] -'0', max_lenght);

    }
   

    return 0;

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
    std::cout << "0 -  выравнивание по левому краю;" << std::endl;
    std::cout << "1 -  выравнивание по центру;" << std::endl;
    std::cout << "2 -  выравнивание по правому краю;" << std::endl;
    std::cout << "3 -  выравнивание по ширине строки." << std::endl;
    std::cout << "4 -  выравнивание лестницей." << std::endl;
    std::cout << "Поддерживается формат выравнивания для каждой строки по отдельности. (несколько цифр без пробелов)" << std::endl;
    std::cout << "Введите тип выравнивания:";
    std::string tf;
    std::getline(std::cin, tf);

    if (Formating(text, text_COUNT, tf, MAX_LENGHT) == 0) {
        for (int i = 0; i < text_COUNT; i++)
        {
            std::cout << text[i] << std::endl;
        }
    }
    else {
        std::cout << "Неверный код форматирования"<< std::endl;
    }

   




}
