// tic-tac-toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "GameManager.h"
#include "GameAI.h"
#include <fstream>

int main()
{
	int size = 20;
	GameManager gm(size);
	GameAI ai1(size);
	//GameAI ai2(size);
	char conf;
	std::cout << "Do you want to play crosses? (N/Y) :";
	std::cin >> conf;
	Move move;
	if (conf == 'N') {
		move = ai1.generate();
		gm.turn(move.x, move.y);
		std::cout << gm.print() << std::endl;
	}
	while (!gm.isGameOver()) {
		std::cout << gm.print() << std::endl;
		int px(-1), py(-1);
		while (px < 0 && py < 0 || py >= size && px >= size) {
			std::cout << "Enter the coordinats in format \"X Y\" : ";
			std::cin >> px >> py;
		}

		gm.turn(px, py);
		std::cout << gm.print() << std::endl;
		if (gm.isGameOver()) break;
		move = ai1.generate(px, py);
		gm.turn(move.x,move.y);
		std::cout << gm.print() << std::endl;
	}
	std::cout << "Very well! Do you wanna save the turns story? (Y/N): ";
	std::cin >> conf;
	if (conf == 'Y') {
		std::string nameout;
		std::cout << "Please, enter the name of file:";
		std::cin >> nameout;
		std::ofstream out(nameout);
		out << gm.getStory();
		out.close();
	}
	std::cout << "Ok, good bye!";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
