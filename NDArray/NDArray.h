#pragma once
#include <type_traits>
#include <vector>
#include <stdarg.h>
#include <string>




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


	
	


private:
	std::vector<int> size;
	T* data;


	int GetFullSize() {
		int full = 0;
		for (int i = 0; i < size.size(); i++)
		{
			full += size[i];
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

		T* data = new T[GetFullSize()];


	}
	NDArray<T>(std::vector<int> init_size) {

		size = init_size;
		T* data = new T[GetFullSize()];

	}
	NDArray<T>(const NDArray<T> *origin) : size(origin->size), data(origin->data) {
	}

	static NDArray<T>* one(std::vector<int> temper) {
		
		NDArray<T> temp = new NDArray<T>(temper);
		for (int i = 0; i < temp.GetFullSize(); i++)
		{
			temp.data[i] = 1;
		}


		return temp;
	}




	static NDArray<T>* one(int n, ...) {
		std::vector<int> temper;
		va_list factor;
		va_start(factor, n);
		for (int i = 0; i < n; i++)
		{
			temper.push_back(va_arg(factor, int));
		}
		va_end(factor);

	
		NDArray<T> temp = new NDArray<T>(temper);
		for (int i = 0; i <temp.GetFullSize() ; i++)
		{
			temp.data[i] = 1;
		}


		return temp;
	}


};

