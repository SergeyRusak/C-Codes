#pragma once
#include <iostream>
using namespace std;
class rational
{
	int numer;
	int denom;


public:
	rational();
	rational(int n);
	rational(double n);
	rational(int n, int d);


	rational& operator +=(const rational& r);
	rational& operator -=(const rational& r);
	rational& operator *=(const rational& r);
	rational& operator /=(const rational& r);

	rational operator +(const rational& r) const;
	rational operator -(const rational& r) const;
	rational operator *(const rational& r) const;
	rational operator /(const rational& r) const;

	rational& operator ++();
	rational operator ++(int);

	bool operator ==(const rational& r) const;
	bool operator !=(const rational& r) const;


	operator int() const;
	operator double() const;

	friend istream& operator >>(istream& in, rational& r);
	friend ostream& operator <<(ostream& out, const rational& r);


	void simplify();
	rational sqrt();






};

