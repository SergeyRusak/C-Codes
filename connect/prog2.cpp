#define _USE_MATH_DEFINES

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>



int main(int argc, char* argv[]) {
	if (argc == 0) {
		std::cout << "Usage: prog2 " << std::endl;
	}

	if (argc == 1) {
		std::ifstream inp("dump.dat");
		std::string dump;

		while (getline(inp, dump)) {
			std::stringstream ss;
			ss.str(dump);
			double x, y, z;
			ss >> x >> y >> z;
			std::cout << 2 * sin(x) * sin(y) + cos(z);

		}

	
		inp.close();
	}

	return 0;
}
