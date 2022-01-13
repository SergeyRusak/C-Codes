#pragma once
#include "Array2D.h"
#include <type_traits>
#include <iostream>


class MatrixException : public std::exception {
    std::string message;

public:
    explicit MatrixException(std::string msg) {
        message = msg;
    }

    ~MatrixException() noexcept override = default;

    const char* what() const noexcept override {
        return message.c_str();
    }
};
template <class T>

class Matrix : public Array2D<T>
{
    static_assert(std::is_arithmetic_v<T>, "Type must be numeric");
public:

    Matrix(int c = 1, int r = 1) :Array2D<T>(c, r) {
    
        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(0, x, y);
            }

        }
    
    }
    Matrix(Matrix &mat):Array2D<T>(mat.getCols(),mat.getRows()) {
        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(mat.get(x,y), x, y);
            }

        }
    }

    Matrix<T>& operator = (Matrix<T> arr) {

        this->cols = arr.getCols();
        this->rows = arr.getRows();
        T** tempdata = new T * [this->cols];
        for (int count = 0; count < this->cols; count++)
            tempdata[count] = new T[this->rows];


        for (int x = 0; x < this->cols; x++)
        {
            for (int y = 0; y < this->rows; y++)
            {
                tempdata[x][y] = arr.get(x, y);
            }

        }
      /*  for (int i = 0; i < this->cols; i++)
        {
            if (this->data[i] != NULL) {
                delete[] this->data[i];
            }

        }
        delete[] this->data;
*/        this->data = tempdata;

        return *this;
    }



    Matrix<T> operator += (Matrix<T> arr) {
        if (this->getCols() != arr.getCols() || this->getRows() != arr.getRows()) throw MatrixException("Matrices sizes don't match!");


        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(arr.get(x, y)+ this->get(x,y), x, y);
            }

        }
        return *this;
    }
    Matrix<T> operator + (Matrix<T> arr) {
        if (this->getCols() != arr.getCols() || this->getRows() != arr.getRows()) throw MatrixException("Matrices sizes don't match!");

        Matrix<T> result = *this;
        result += arr;
        return result;
    }

    Matrix<T> operator *= (T elem) {

        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(this->get(x, y) * elem, x, y);
            }

        }
        return *this;

    }
    Matrix<T> operator * (T elem) {
        Matrix<T> result = *this;
        result *= elem;
        return result;
    }


    Matrix<T> operator -=(Matrix<T> arr) {
        if (this->getCols() != arr.getCols() || this->getRows() != arr.getRows()) throw MatrixException("Matrices sizes don't match!");


        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(this->get(x, y)-arr.get(x, y), x, y);
            }

        }
        return *this;
    }
    Matrix<T> operator - (Matrix<T> arr) {
        if (this->getCols() != arr.getCols() || this->getRows() != arr.getRows()) throw MatrixException("Matrices sizes don't match!");

        Matrix<T> result = *this;
        result -= arr;
        return result;
    }

    Matrix<T> operator *=(Matrix<T> arr) {
        if (this->getCols() != arr.getRows()|| this->getRows() != arr.getCols()) throw MatrixException("Matrices must be square!");
        Matrix<T> result(arr.getCols(), this->getRows());
        for (int x = 0; x < result.getCols(); x++)
        {
            for (int y = 0; y < result.getRows(); y++)
            {
                int td = 0;
                for (int i = 0; i < this->getCols(); i++)
                {
                    td += this->get(i, y) * arr.get(x, i);
                }
                result.set(td, x, y);
            }

        }
        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                this->set(result.get(x, y), x, y);
            }

        }
    }

   
    Matrix<T> operator * (Matrix<T> arr) {
        if (this->getCols() != arr.getRows()) throw MatrixException("Matrices don't match sides!");
        Matrix<T> result(arr.getCols(), this->getRows());
        for (int x = 0; x < result.getCols(); x++)
        {
            for (int y = 0; y < result.getRows(); y++)
            {
                int td = 0;
                for (int i = 0; i < this->getCols(); i++)
                {
                    td += this->get(i, y) * arr.get(x, i);
                }
                result.set(td, x, y);
            }

        }
        return result;

    }

    Matrix<T> transp() {
        Matrix<T> result(this->getCols(),this->getRows());

        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                result.set(this->get(x, y), y, x);
            }

        }
        return result;
    }
    Matrix<T> operator ^(int power) {
        if (power <= 1) throw MatrixException("Power must be more than 1");


        Matrix<T> result = *this;
        Matrix<T> origin = *this;
        for (int i = 1; i < power; i++)
        {
            result *= origin;
        }
        return result;
    }

    Matrix<T>& getMinor(int ix, int iy) {
        Matrix<T> proc(this->getCols() - 1, this->getRows() - 1);
        int xx(0), yy(0);
        for (int x = 0; x < this->getCols(); x++)
        {
            if (x == ix) continue;
            yy = 0;
            for (int y = 0; y < this->getRows(); y++) {
                if (y == iy)continue;
                proc.set(this->get(x, y), xx, yy);
                yy++;
            }
            xx++;
        }
        return proc;

    }


    T det() {
        if (this->getCols() != this->getRows()) throw MatrixException("Matrix must be square!");

        if (this->getCols() == 2) return this->get(0, 0) * this->get(1, 1) - this->get(1, 0) * this->get(0, 1);

        T deter = 0;
        int k = -1;
        for (int x = 0; x < this->getCols(); x++) {
            k = -k;
            deter += this->get(x, 0) * this->getMinor(x, 0).det()*k;
            
        }
        
        return deter;
    }

    Matrix<double> getInvert() {
        T det = this->det();
        if (det == 0) throw MatrixException("Inverted Matrix doesn't exist. Determinant equals zero.");
        Matrix<T> transMinors(this->getCols(), this->getRows());

        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                transMinors.set(this->transp().getMinor(x, y).det(), x, y);
            }
        }
        Matrix<double> result(this->getCols(), this->getRows());

        for (int x = 0; x < this->getCols(); x++)
        {
            for (int y = 0; y < this->getRows(); y++)
            {
                result.set(transMinors.get(x, y) / (double)det,x,y);
            }
        }

        return result;
    }



};