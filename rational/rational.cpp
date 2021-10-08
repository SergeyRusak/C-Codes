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

	long long lln = *(long long*)&n;
	int r = (int)((lln >> 52) & 0x000007FF) - 1023;
	lln = (lln & 0x000FFFFFFFFFFFFF)|0x0010000000000000;
	numer = (r >= 0) ? lln << ((long long)(r)) : lln >> (long long)(-r);
	denom = (long long)(1) << 52;

	simplify_equlid();
	


}
rational::rational(int n, int d)
{
	numer = n;
	denom = d;
	simplify_equlid();
}

rational& rational::operator +=(const rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify_equlid();
	return *this;
}
rational& rational::operator -=(const rational& r)
{
	numer = (numer * r.denom - denom * r.numer);
	denom *= r.denom;
	simplify_equlid();
	return *this;
}
rational& rational::operator *=(const rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify_equlid();
	return *this;
}
rational& rational::operator /=(const rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify_equlid();
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

rational rational::operator ++()
{
	rational r(*this);
	r.numer += r.denom;
	return r;
}
rational rational::operator ++(int)
{
	rational r(*this);
	r.numer += r.denom;
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
	r.simplify_equlid();
	return in;
}
ostream& operator <<(ostream& out, const rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}


double rational::sqrt(long long a, double x, int TTL) {
	if (a / x > LLONG_MAX - x) return x;
	double xi = (x + (a / x)) * 0.5;
	return (xi == x|| TTL==0) ? (xi) : (sqrt(a,xi,TTL-1));
}

double rational::sqrt(long long a) {
	return sqrt(a, 3.0, 255);
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
void rational::simplify_equlid()
{
	long long t, num,den;
	num = abs(numer);
	den = abs(denom);
	while (den != 0) {
		t = den;
		den = num % den;
		num = t;
	}
	denom /= num;
	numer /= num;

}
rational rational::sqrt() {

	rational n(sqrt(numer));
	rational d(sqrt(denom));

	return n / d;
}
