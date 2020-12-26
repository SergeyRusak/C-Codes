#include <iostream>
#include <locale.h>
#include <string>
std::string encode(int n) {
    return ((n == 0) ? ("A") : ((n == 1) ? ("B") : ((n == 2) ? ("C") : ((n == 3) ? ("D") : ("0")))));
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите натуральное число:";
    do {
        std::cin >> n;
    } while (n < 0);
    
    std::string code;
    while (n != 0) {
        if (n < 4) {
            code.append(encode(n-1));
            break;
        }
        code.append(encode(n % 4-1));
        n /= 4;
        
    }
    std::reverse(code.begin(), code.end());
 

  
    std::cout << "Код:"<< code << std::endl;
    system("pause");
    }  