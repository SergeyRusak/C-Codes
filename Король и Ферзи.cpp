#include <iostream>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");

    int xk,yk,xf,yf;
    int field[8][8] = { {2,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,2,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,2},
                        {0,2,0,0,0,0,0,0},
                        {0,0,0,0,0,2,0,0},
                        {0,0,2,0,0,0,0,2} };

    std::cout << "произошло заполнение поля " << std::endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 1) {
                xk = j;
                yk = i;
                goto kingFind;
            }
        }
    }
 kingFind:
    bool anyRisk = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 2) {
                xf = j;
                yf = i;
                int xv = xf - xk;
                int yv = yf - yk;
                if (xv == 0 || yv == 0 || abs(xv) == abs(yv)) {
                    if (!anyRisk) {
                        anyRisk = true;
                        std::cout << "Угрожающие королю Ферзи стоят на координатах: ( В формате строка:столбец)" << std::endl;
                    }
                    std::cout << "(" << yf << ":" << xf << ")" << std::endl;

                }


               
            }
        }
    }
    if (!anyRisk)std::cout << "Королю ничего не угрожает";

    
    system("pause");
}