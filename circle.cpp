#include <iostream>

int main()
{
	const int YMAX = 11;
	const int XMAX = 11;
	int A [YMAX][XMAX] = {
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						};
	int up = 0;
	int down = 0;
	int left = 0;
	for (int y = 0; y < YMAX; y++) {
		for (int x = 0; x < XMAX; x++) {
			
			if (A[y][x] &&
				((A[y + 0][ x + 1] && A[y + 1][ x - 1]) ||
				 (A[y + 1][ x + 1] && A[y + 1][ x - 1]))) {
				up = y;
				continue;
			}
			if (A[y][ x] &&
				((A[y - 1][ x + 1] && A[y + 1][ x - 0]) ||
				 (A[y + 1][ x + 1] && A[y - 1][ x + 1]))) {
				left = x;
				continue;
			}
			if (A[y][ x] &&
				((A[y - 1][ x - 1] && A[y + 0][ x + 1]) ||
				 (A[y - 1][ x + 1] && A[y - 1][ x - 1]))) {
				down = y;
				continue;
			}

				
		}
	}

	int R = (down - up) / 2;
	int Xo = left + R;
	int Yo = up + R;
	std::cout << R << "-R (" << Xo << ":" << Yo << ")-center" << std::endl;
	system("pause");
	return 0;   
}
