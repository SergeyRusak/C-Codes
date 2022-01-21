#pragma once
#include "Cell.h"
class Field
{
private:
	Cell **cells;
	int size;

public:
	Field(int n = 5) {
		size = (n < 5)?(5):(n);

		cells = new Cell* [size];
		for (int i = 0; i < size; i++)
		{
			cells[i] = new Cell[size];
		}
		clear();
	}
	Field(Field& f) {
		size = f.size;

		cells = new Cell * [size];
		for (int i = 0; i < size; i++)
		{
			cells[i] = new Cell[size];
		}


		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cells[i][j].set(f.get(j,i));
			}
		}
		
	}
	Field& operator = (Field* f) {
		this->~Field();



		size = f->getSize();

		cells = new Cell * [size];
		for (int i = 0; i < size; i++)
		{
			cells[i] = new Cell[size];
		}


		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cells[i][j].set(f->get(j, i));
			}
		}





		return *this;
	}


	~Field() {

		for (int i = 0; i < size; i++)
		{
			delete[] cells[i];
		}
		delete[] cells;
	}
	

	void set(int x, int y, int turn) {
		cells[y][x].set(turn);
	}
	int get(int x, int y) {
		return cells[y][x].get();
	}
	int getSize() { return size; }

	void clear() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cells[i][j].set(0);
			}
		}
	}

};

