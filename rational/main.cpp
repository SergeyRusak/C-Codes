#include <iostream>
#include "rational.h"
using namespace std;
int main()
{
    rational a(225,625), b(100),c(rational(25,100)),d(14.165);
    cout << a+b << endl
         << a.sqrt() << endl
         << b*c << endl
         << a-c << endl
         << rational()++ << endl
         << ++b;
}
