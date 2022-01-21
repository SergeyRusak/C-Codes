#pragma once
class Move {
public:
	int x;
	int y;
	int att;
	int def;

	Move(int xi = 0, int yi = 0) {
		x = xi;
		y = yi;
	}
};