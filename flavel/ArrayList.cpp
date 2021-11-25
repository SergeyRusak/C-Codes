#include "ArrayList.h"

void ArrayList::expand(int newCapacity)
{
	capacity = (newCapacity < capacity * 2) ? (capacity * 2) : (newCapacity);
	int* newData = new int[capacity];
	for (int i = 0; i < size; i++)
		newData[i] = data[i];
	delete[] data;
	data = newData;
}

ArrayList::ArrayList(int startCapacity)
{
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	data = new int[capacity];
	size = 0;
}

ArrayList::~ArrayList()
{
	delete[] data;
}

ArrayList::ArrayList(const ArrayList& arr)
{
	data = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++)
		data[i] = arr.data[i];

}

ArrayList& ArrayList::operator=(const ArrayList& arr)
{
	if (this == &arr)
		return *this;
	if (capacity != arr.capacity)
	{
		delete[] data;
		data = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (int i = 0; i < size; i++)
		data[i] = arr.data[i];
	return *this;

}

void ArrayList::insert(int elem, int index)
{
	if (index < 0 || index > size)
		throw ArrayException();
	if (size == capacity)
		// Закрытая функция, увеличивающая предельный размер
		expand(size + 1);
	// Если index==size, этот цикл не выполнится ни разу
	for (int j = size - 1; j >= index; j--)
		data[j + 1] = data[j];
	size++;
	data[index] = elem;
}

void ArrayList::insert(int elem)
{
	insert(elem, size);
}

void ArrayList::remove(int index)
{
	if (index < 0 || index >= size)
		throw ArrayException();
	for (int j = index; j < size - 1; j++)
		data[j] = data[j + 1];
	data[size - 1] = 0;
	size--;

}

std::ostream& operator<<(std::ostream& out, const ArrayList& arr)
{
	out << "Total size: " << arr.size << std::endl;
	for (int i = 0; i < arr.size; i++)
		out << arr.data[i] << " ";
	out << std::endl;
	return out;// TODO: вставьте здесь оператор return
}
