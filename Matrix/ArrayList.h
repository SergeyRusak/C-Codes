#pragma once
#include <ostream>
#include <ostream>

const int DEFAULT_CAPACITY = 10;
class ArrayException {};
template <class T>
class ArrayList
{
	T* data;

	int size, capacity;


	void expand(int newCapacity) {
		capacity = (newCapacity < capacity * 2) ? (capacity * 2) : (newCapacity);
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++)
			newData[i] = data[i];
		delete[] data;
		data = newData;
	}
public:
	ArrayList<T>(int startCapacity = DEFAULT_CAPACITY)
	{
		if (startCapacity <= 0)
			capacity = DEFAULT_CAPACITY;
		else
			capacity = startCapacity;
		data = new T[capacity];
		size = 0;
	}
	~ArrayList<T>()
	{
		delete[] data;
	}
	ArrayList<T>(const ArrayList<T>& arr) 
	{
		data = new T[arr.capacity];
		size = arr.size;
		capacity = arr.capacity;
		for (int i = 0; i < size; i++)
			data[i] = arr.data[i];

	}


	T& operator[] (int index) { if (index < 0 || index >= size)throw ArrayException(); return data[index]; }
	ArrayList<T>& operator= (const ArrayList<T>& arr) 
	{
		if (this == &arr)
			return *this;
		if (capacity != arr.capacity)
		{
			delete[] data;
			data = new T[arr.capacity];
			capacity = arr.capacity;
		}
		size = arr.size;
		for (int i = 0; i < size; i++)
			data[i] = arr.data[i];
		return *this;

	}

	void insert(T elem, int index) {
		if (index < 0 || index > size)
			throw ArrayException();
		if (size == capacity)
			expand(size + 1);
		for (int j = size - 1; j >= index; j--)
			data[j + 1] = data[j];
		size++;
		data[index] = elem;
	}
	void insert(T elem) 
	{
		insert(elem, size);
	}
	void remove(int index)
	{
		if (index < 0 || index >= size)
			throw ArrayException();
		for (int j = index; j < size - 1; j++)
			data[j] = data[j + 1];
		data[size - 1] = 0;
		size--;

	}
	int getSize() const { return size; }
	friend std::ostream& operator<< (std::ostream& out, const ArrayList& arr) {
		out << "Total size: " << arr.size << std::endl;
		for (int i = 0; i < arr.size; i++)
			out << arr.data[i] << " ";
		out << std::endl;
		return out;
	}
};
