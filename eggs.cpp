#include <iostream>
#include <string>
#include <locale.h>



int powof(int a, int N){
    int otv = 1;
    int an = a;
    while (an<N){
        otv++;
        an*=a;
    }
    return otv;
}
int search2 (int N)
{
    int result=100000;
    for (int i =1; i<=N;i++)
    {
        if (result > (N+i-1)/i+i-1) result = (N+i-1)/i+i-1;
    }
    return result;
}

int powin( int a, int b){
 int otv = a;
 for (int i=1; i <b;i++){
  otv*=a;   
 }
 return otv;
}



int main()
{ 
setLocale(LC_ALL,"Russian");   
    
int H, nE,E, otv;
float temp;


do
{
    std::cout <<"Введите высоту здания :";
    std::cin >>temp;
}
while(temp<0 || temp-(int)temp!=0);
H=(int)temp;


do
{
    std::cout <<"Введите количество яиц :";
    std::cin >>temp;
}
while(temp<0 || temp-(int)temp!=0);
E=(int)temp;


nE = powof(2,H);
if (E==1) otv = H;
    else if (E==2) otv = search2(H);
        else if (E>2 && E<nE) otv =search2 (H/powin(2,E-2))+E-2;
            else otv = nE;
    
 std::cout<<""<<otv<<std::endl;
}
