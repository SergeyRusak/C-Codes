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


int main()
{
	setlocale(LC_ALL, "Russian");
	int n,H,otv;

	do{
		std::cout << "Введите кол-во яиц :";
		std::cin >> n;
	}
	while(n<1);

	do{
		std::cout << "Введите кол-во этажей :";
		std::cin >> H;
	}
	while(H<1);

	int nE = powof(2,H);

	if (n==1)   otv = H;
	if (n==2)   otv = search2(H);
	if (n>2 && n<nE) otv = search2(H/powin(2,n-2))+(n-2);
	if (n>=nE)  otv = nE;

	std::cout <<"Минимальное необходимое кол-во попыток :"<<otv << std::endl;
	system("pause");

    return 0;
}