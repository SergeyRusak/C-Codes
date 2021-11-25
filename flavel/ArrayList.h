#pragma once
#include <ostream>
#include <ostream>

const int DEFAULT_CAPACITY = 10;
class ArrayException {};
class ArrayList
{
	int* data;

	int size, capacity;


	void expand(int newCapacity);
public:
	explicit ArrayList(int capacity=DEFAULT_CAPACITY);
	~ArrayList();
	ArrayList(const ArrayList& arr);


	int& operator[] (int index) { if (index < 0 || index >= size)throw ArrayException(); return data[index]; }
	ArrayList& operator= (const ArrayList& arr);

	void insert(int elem, int index);
	void insert(int elem);
	void remove(int index);
	int getSize() const { return size; }
	friend std::ostream& operator<< (std::ostream& out, const ArrayList& arr);
	};

