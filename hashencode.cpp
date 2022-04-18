#include <iostream>

char hash1(char a1, char a2) {
    return a1 ^ a2;
}


int main()
{
    std::string text;
    std::cout << "Enter the text:";
    std::cin >> text;
    char hash = 0;
    for (int i = 0; i < text.size(); i++)
    {
        hash = hash1(hash, int(text[i]));
    }
    std::cout << "Your hash:" << hash << std::endl;
}
