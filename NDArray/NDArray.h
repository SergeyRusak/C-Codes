#pragma once
#include <type_traits>
#include <vector>
#include <stdarg.h>
#include <string>
#include <ctime>
#include <functional>




class NDArrayException: public std::exception {
private:
	std::string message_;
public:

	NDArrayException(std::string strm) {
		message_ = strm;
	}

	const char* what() const noexcept override {
		return message_.c_str();
	}


};
template <typename T>
class NDArray
{
	static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");


	
	T* data;

private:

	std::vector<int> size;
	


	int GetFullSize() {
		int full = 1;
		for (int i = 0; i < size.size(); i++)
		{
			full *= size[i];
		}
		return full;
	}

	int GetLinearIndex(std::vector<int> index) {

		if (index.size() != size.size()) {
			throw NDArrayException("The index must contain the same number of dimensions as the array itself!");
		}

		int result = 0;
		for (int i = 0; i < index.size() ; i++)
		{
			int temp = index[i];
			for (int j = i + 1; j < index.size() ; j++)
			{
				temp *= size[j];
			}
			result += temp;

		}

		return result;
	}

	bool CheckIndex(int index) {
		if (index < 0 || index >= GetFullSize()) throw new NDArrayException("Index out of bounds!");



		return true;
	}
	bool CheckIndex(std::vector<int> index) {

		if (index.size() != size.size()) throw new NDArrayException("Wrong dimensional");

		for (int i = 0; i < index.size(); i++)
		{
			if (size[i] != index[i]) throw  NDArrayException("index shape doesn't match");
		}


		return CheckIndex(GetLinearIndex(index));
	}
	


	/* std::vector<int> getVectorFromParametrs(int* p) {

		std::vector<int> temp;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temp.push_back(va_arg(factor, int));
		}
		va_end(factor);

		return temp;
	}
	*/ // just paste it in code when you want to get vector from unknown count parametrs

	// math multyfunctional


	static NDArray<T> math(NDArray<T> a, NDArray<T> b, std::function<T(T,T)> func) {
		if (a.GetFullSize() != b.GetFullSize()) throw NDArrayException("NDArrays sizes doesn't match");

		for (int i = 0; i < a.size.size(); i++)
		{
			if (a.size[i] != b.size[i] ) throw  NDArrayException("NDArrays shapes doesn't match");
		}

		NDArray<T> result(a.size);

		for (int i = 0; i < a.size.size(); i++)
		{
			result.set(i, func(a.get(i), b.get(i)));
		}

		return result;

	}

	







public:

	NDArray<T>(int n, ...) { // example:  NDArray<int> (3,x,y,z);

		std::vector<int> temp;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temp.push_back(va_arg(factor, int));
		}
		va_end(factor);

		size = temp;
		data = (T*) malloc(sizeof(T) * GetFullSize());
		if (data == nullptr) throw NDArrayException("malloc give nullptr");


	}
	NDArray<T>(std::vector<int> init_size) {

		size = init_size;
		data = (T*) malloc(sizeof(T) * GetFullSize());
		if (data == nullptr) throw NDArrayException("malloc give nullptr");

	}

	//~NDArray<T>() {
	//	delete[] data;
	//}



	void set(int index, T value) {//linear
		this->data[index] = value;
	}
	void set(std::vector<int> index, T value) {//multydim

		if (index.size() != size.size()) {
			throw NDArrayException("The index must contain the same number of dimensions as the array itself!");
		}

		set(GetLinearIndex(index), value);
	}

	T get(int index) {
		CheckIndex(index);
		return data[index];
	}
	T get(std::vector<int> index) {
		return get(GetLinearIndex(index));
	}
	




	T& operator[](int index) {
		//throw new NDArrayException("Not Implemented yet");
		CheckIndex(index);
		return data[index];
	}

	T& operator[](std::vector<int> index) {
		CheckIndex(index);
		return data[GetLinearIndex(index)];
	}




	NDArray<T>* operator= (NDArray<T> target) {

		delete[] data;
		size.clear();
		for (int i = 0; i < target.size.size(); i++)
		{
			size.push_back(target.size[i]);
		}
		
		data = (T*)malloc(sizeof(T) * GetFullSize());

		for (int i = 0; i < GetFullSize(); i++)
		{
			set(i,target.get(i));
		}


		return this;
	}

	NDArray<T>(NDArray<T> *target)
	{
		size = std::vector<int>();
		for (int i = 0; i < target->size.size(); i++)
		{
			size.push_back(target->size[i]);
		}

		data = (T*)malloc(sizeof(T) * GetFullSize());

		for (int i = 0; i < GetFullSize(); i++)
		{
			set(i, target->get(i));
		}
	}



// fill functions


	void fill(T value) {

		for (int i = 0; i < GetFullSize(); i++)
		{
			set(i, value);
		}

	}

	static NDArray<T> one(std::vector<int> temper) {
		
		NDArray<T> temp = new NDArray<T>(temper);
		temp.fill(1);
		return temp;
	}

	static NDArray<T> one(int n, ...) {
		std::vector<int> temper;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temper.push_back(va_arg(factor, int));
		}
		va_end(factor);

		NDArray<T> temp = new NDArray<T>(temper);
		temp.fill(1);

		return temp;
	}

	static NDArray<T> zero(std::vector<int> temper) {

		NDArray<T> temp = new NDArray<T>(temper);
		temp.fill(0);


		return temp;
	}

	static NDArray<T> zero(int n, ...) {
		std::vector<int> temper;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temper.push_back(va_arg(factor, int));
		}
		va_end(factor);

		NDArray<T> temp = new NDArray<T>(temper);
		temp.fill(0);
		return temp;
	}





	static NDArray<T> rand(std::vector<int> temper) {

		std::srand(std::time(nullptr));


		NDArray<T> temp = new NDArray<T>(temper);
		for (int i = 0; i < temp.GetFullSize(); i++)
		{
			temp.set(i, (T)std::rand());
		}
		return temp;
	}

	static NDArray<T> rand(int n, ...) {

		std::srand(std::time(nullptr));


		std::vector<int> temper;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temper.push_back(va_arg(factor, int));
		}
		va_end(factor);

		NDArray<T> temp = new NDArray<T>(temper);
		for (int i = 0; i < temp.GetFullSize(); i++)
		{
			temp.set(i,(T) std::rand());
		}

		return temp;
	}


	// math functions


	NDArray<T> operator+ (NDArray<T> b) {

		NDArray<T> test = NDArray<T>::math(this, b,
			[](T a, T b)
			{
				return a + b;
			});

			return test;
	}
	NDArray<T> operator- (NDArray<T> b) {

		NDArray<T> test = NDArray<T>::math(this, b,
			[](T a, T b)
			{
				return a - b;
			});
			
			return test;
	}
	NDArray<T> operator* (NDArray<T> b) {

		NDArray<T> test = NDArray<T>::math(this, b,
			[](T a, T b)
			{
				return a * b;
			});

			return test;
	}
	NDArray<T> operator/ (NDArray<T> b) {

		NDArray<T> test = NDArray<T>::math(this, b,
			[](T a, T b)
			{
				return a / b;
			});

			return test;
	}


	NDArray<T> MatrixMultiply(NDArray<T> b) {
		NDArray<T> a = *this;

		if (a.size.size() != 2 || b.size.size() != 2) throw new NDArrayException("Matrix must have only two dime");

		if (a.size[1] - b.size[0] !=0) throw new NDArrayException("Matrix must have same size by one side!");

		NDArray<T> result = NDArray<T>::one(2,a.size[0], b.size[1]);

		for (int ry = 0; ry < result.size[0]; ry++)
		{
			for (int rx = 0; rx < result.size[1]; rx++)
			{
				std::vector<int> index;
				index.push_back(ry);
				index.push_back(rx);



				T temp = 0;
				for (int i = 0; i < a.size[1]; i++)
				{
					std::vector<int> indexa;
					indexa.push_back(ry);
					indexa.push_back(i);
					std::vector<int> indexb;
					indexb.push_back(i);
					indexb.push_back(rx);

					temp += a.get(indexa) * b.get(indexb);
				}

				result.set(GetLinearIndex(index), temp);

			}

		}

		return result;

	}
	
	NDArray<T> MatrixTransp() {
		NDArray<T> a = *this;

		if (a.size.size() != 2) throw new NDArrayException("Matrix must have only two dime");


		NDArray<T> result = NDArray<T>::one(2, a.size[1], a.size[0]);

		for (int ry = 0; ry < result.size[0]; ry++)
		{
			for (int rx = 0; rx < result.size[1]; rx++)
			{
				std::vector<int> indexold;
				indexold.push_back(rx);
				indexold.push_back(ry);
				std::vector<int> indexnew;
				indexnew.push_back(ry);
				indexnew.push_back(rx);
				

				result.set(result.GetLinearIndex(indexnew), a.get(indexold));

			}

		}

		return result;

	}






};

