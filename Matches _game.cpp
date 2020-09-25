#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");
  int N,user;
  do{std::cout<<"Введите начальное кол-во спичек в куче (больше нуля) >>";
  std::cin >>N;
  }while(N<1);
  while (N>0){
      do{std::cout<<"Введите кол-вол спичек (от 1 до 5) >>";
   std::cin >> user;
      }while(user>5||user<1);
   N-=user;
   if (N<=0){std::cout<<"Вы проиграли"<<std::endl; break;}
   std::cout<<"Осталось спичек:"<<N<<std::endl;
   int t = ((N-1)%6>0)?((N-1)%6):(1);
   std::cout<<"Компьютер берёт "<<t <<std::endl;
   N-= t;
      std::cout<<"Осталось спичек:"<<N<<std::endl;
   if (N<=0){std::cout<<"Вы победили"<<std::endl; break;}
  }
}
