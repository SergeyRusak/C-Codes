#include <iostream>

int pickN(int n1,int n2,int n3){
	n1*=(n3-1)%6>0;
	n2*=(n3-1)%6>0;
	n3*=(n3-1)%6>0;
	if (n1<=n2 && n1<=n3 && n1-1>0) return 1;
	if (n2<=n1 && n2<=n3 && n2-1>0) return 2;
	if (n1<=n2 && n1<=n3 && n3-1>0) return 3;
	return 3;
	}

int _tmain(int argc, _TCHAR* argv[]){
	setlocale(LC_ALL, "Russian");

	int N,user1,user2,user3;
	int N1,N2,N3;
	int c1,c2,c3;

	do{
		std::cout<<"Введите начальное кол-во спичек в куче (больше нуля и кратно трём) >>";
		std::cin >>N;
	}while(N<1 && N%3!=0);
	N1=N/3;
	N2=N1;
	N3=N1;

	while (N1>0&&N2>0&&N3>0){
		do{
			std::cout<<"Введите кол-вол спичек, которое хотите взять из каждой кучки (от 1 до 5 в сумме) >>";
			std::cin >> user1 >> user2>> user3;
		}while(user1+user2+user3>5||user1+user2+user3<1);
		
		N1-=user1;
		N2-=user2;
		N3-=user3;
		if (N1<=0||N2<=0||N3<=0){
			std::cout<<"Вы проиграли"<<std::endl;
			break;
		}
		std::cout<<"Осталось спичек:"<<N1<<" "<<N2<<" "<<N3<<std::endl;
		c1=0;
		c2=0;
		c3=0;

		if (pickN(N1,N2,N3)==1) c1=( (N1-1)%6>0 )? (N1-1)%6: 1;
		else
			if (pickN(N1,N2,N3)==2) c2=(N2-1)%6>0? (N2-1)%6: 1;
			else
				if (pickN(N1,N2,N3)==3) c3=(N3-1)%6>0? (N3-1)%6: 1;
		
		std::cout<<"Компьютер берёт "<<c1<<" "<<c2<<" "<<c3<<std::endl;
		N1-=c1;
		N2-=c2;
		N3-=c3;




		std::cout<<"Осталось спичек:"<<N1<<" "<<N2<<" "<<N3<<std::endl;
		if (N1<=0||N2<=0||N3<=0){
			std::cout<<"Вы победили"<<std::endl;
			break;
		}
	}

	std::cin.get();

	system("pause");

	return 0;
}



