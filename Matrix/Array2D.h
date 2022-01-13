#pragma once
#include "ArrayList.h"
template <class T>
class Array2D
{
public:
	T** data;
	int cols, rows;
	bool is_correct(int x, int y) {
		return !(x < 0 || x >= cols || y < 0 || y >= rows);
	}



	Array2D(int c=1, int r=1) {
		cols = c;
		rows = r;
		data = new T* [cols];
		for (int count = 0; count < c; count++)
			data[count] = new T[rows];
	}
	~Array2D() = default;
	/*
	~Array2D() {
		for (int i = 0; i < cols; i++)
		{
			if (data[i] != NULL) {
				delete[] data[i];
			}

		}
		if (data != NULL) {
			delete[] data;
		}
	}
	*/
	Array2D(Array2D<T> &arr) {
		cols = arr.getCols();
		rows = arr.getRows();
		data = new T * [cols];
		for (int count = 0; count < cols; count++)
			data[count] = new T[rows];


		for (int x = 0; x < cols; x++)
		{
			for (int y = 0; y < rows; y++)
			{
				data[x][y] = arr.get(x, y);
			}

		}
	}

	Array2D& operator = (const Array2D arr) {
		cols = arr.getCols();
		rows = arr.getRows();
		T** tempdata = new T* [cols];
		for (int count = 0; count < cols; count++)
			tempdata[count] = new T[rows];

		
		for (int x = 0; x < cols ; x++)
		{
			for (int y = 0; y < rows; y++)
			{
				tempdata[x][y] = arr.get(x, y);
			}

		}
		/*for (int i = 0; i < cols; i++)
		{
			if (data[i] != NULL) {
				delete[] data[i];
			}

		}
		delete[] data;*/
		data = tempdata;
		return *this;
	}



	void set(T elem, int x, int y) {
		if (!is_correct(x,y)) throw ArrayException();
		data[x][y] = elem;
	}




	T get(int x, int y) {
		if (!is_correct(x, y)) throw ArrayException();
		return data[x][y];
	}

	int getCols() {
		return cols;
	}

	int getRows() {
		return rows;
	}

	
};
