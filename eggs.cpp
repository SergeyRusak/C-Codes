#include <iostream>
#include <string>
#include <locale.h>
#include <math.h>



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
   
    return ceil(((sqrt(1+8*N)-1)/2.0));
}

int powin( int a, int b){
 int otv = a;
 for (int i=1; i <b;i++){
  otv*=a;   
 }
 return otv;
}
