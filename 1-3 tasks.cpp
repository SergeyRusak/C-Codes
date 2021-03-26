#include <iostream>
#include <string>


double power(double n, int a) {
    return (a > 0) ? (n*power(n, a - 1)) : (1);
}



int sum(int origin) {
    return (origin / 10 > 0) ? (origin % 10 + sum(origin / 10)) : (origin);
}



void n_to_base(int n , int base) {
    if (n < 0) {
        std::cout << "-";
        n_to_base(-n, base);
    }
    else if (n < base) {
        std::cout << n;
        return;
    }
    else {
        n_to_base(n / base, base);
        int res = n % base;
        std::cout << res;
    }
}







int main()
{
    std::cout << "2 pow 5 =" << power(2, 5) << "  (32)" << std::endl;
    std::cout << "sum 123456 = " << sum(123456) << "  (21)" << std::endl;
    std::cout << "64 in base 2 = "; n_to_base(64, 2);std::cout << "  (1000000)" << std::endl;
}
