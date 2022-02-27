#!
#define _USE_MATH_DEFINES

#include <fstream>
#include <iostream>
#include <math.h>



int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Usage: prog1 int" << std::endl;
	}

	if (argc == 2) {
		srand(time(NULL));
		std::ofstream outp("dump.dat");

		for (int i = 0; i < std::atoi(argv[1]); i++)
		{
			double x(rand()/RAND_MAX*(2*M_PI)-M_PI), y(rand() / RAND_MAX * (2 * M_PI) - M_PI), z(rand() / RAND_MAX * (2 * M_PI) - M_PI);
			outp << x << " " << y << " " << z << std::endl;
		}
		outp.close();
	}

	return 0;
}
