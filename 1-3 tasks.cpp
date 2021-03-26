#include <iostream>
#include <string>

double power(double n, double origin, int a) {
    return (a > 1) ? power(n * origin, origin, a - 1) : n;
}

double power(double n, int a) {
    return (a > 1) ? power(n * n, n, a - 1) : n ;
}


int sum(int n, int summ) {
    return (n / 10 > 0) ? (sum(n / 10, summ + n % 10)) : (summ + n);

}
int sum(int origin) {
    return (origin / 10 > 0) ? (sum(origin / 10, origin % 10)) : (origin);
}




std::string rev(std::string v) {
    std::reverse(v.begin(), v.end());
    return v;
}

std::string n_to_base(int N, int base, std::string code) {
    return (N / base != 0) ? (n_to_base(N/base, base, code +std::to_string(N % base))) : (rev(code+ std::to_string(N) ));

}

std::string n_to_base(int N, int base) {
   return (N / base != 0) ? (n_to_base(N / base, base,std::to_string(N % base))) : (std::to_string(N));
}







int main()
{
    std::cout <<"2 pow 5 ="<< power(2, 5) <<"  (32)"<< std::endl;
    std::cout <<"sum 123456 = "<< sum(123456) <<"  (21)"<< std::endl;
    std::cout << "64 in base 2 = " << n_to_base(64,2) <<"  (1000000)"<< std::endl;
}
