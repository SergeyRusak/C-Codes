#pragma once
class Cell
{
private:
	int fill; // 0-empty 1-cross, 2-circle

public:
	Cell() {
		fill = 0;
	}
	int get() { return fill; }
	void set(int i) { fill = i; }
};

