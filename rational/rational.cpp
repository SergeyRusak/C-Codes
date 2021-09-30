#include "rational.h"
#include <math.h>
#include <string>

rational::rational()
{
	numer = 0;
	denom = 1;
}
rational::rational(int n)
{
	numer = n;
	denom = 1;
}
rational::rational(double n) {
	// not the best solution
	string s = to_string(n);
	int exp = (s[0] != '0') ? (s.length()-2) : (s.length()-1);
	numer = n * std::pow(10, exp);
	denom = std::pow(10, exp);
	simplify();


}
rational::rational(int n, int d)
{
	numer = n;
	denom = d;
	simplify();
}

rational& rational::operator +=(const rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
rational& rational::operator -=(const rational& r)
{
	numer = (numer * r.denom - denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
rational& rational::operator *=(const rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
rational& rational::operator /=(const rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}

rational rational::operator +(const rational& r) const
{
	rational res(*this);
	return res += r;
}
rational rational::operator -(const rational& r) const
{
	rational res(*this);
	return res -= r;
}
rational rational::operator *(const rational& r) const
{
	rational res(*this);
	return res *= r;
}
rational rational::operator /(const rational& r) const
{
	rational res(*this);
	return res /= r;
}

rational& rational::operator ++()
{
	numer += denom;
	return *this;
}
rational rational::operator ++(int)
{
	rational r(*this);
	numer += denom;
	return r;
}

bool rational::operator ==(const rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}
bool rational::operator !=(const rational& r) const
{
	return !(*this == r);
}

rational::operator int() const
{
	return numer / denom;
}
rational::operator double() const
{
	return ((double)numer) / denom;
}

istream& operator >>(istream& in, rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}




void rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}
rational rational::sqrt() {

	rational n = std::sqrt(numer);
	rational d = std::sqrt(denom);

	return n / d;
}