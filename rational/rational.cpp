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
	lln = (lln & 0x000FFFFFFFFFFFFF) | 0x0010000000000000;
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

rational::operator long long() const
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


rational rational::sqrt(rational a, rational x, int TTL) {
	//if ((a.numer * x.denom * x.denom + a.denom * x.numer * x.numer < 0) || (a.denom * x.numer * x.denom < 0)) {
	if ((long long)(x + (a / x))<0){
		return x;
	} //положительное число под корнем никогда не будет отрицательным ( такая роспись сделана для проверки двух минусов)
	//эта роспись эквивалентна числителю и знаменателю результата x+(a/x)
	rational xi = rational(1, 2)*(x + (a / x));
	return (xi == x || abs((double)xi - (double)x) < 0.0000001 || TTL == 0) ? (xi) : (sqrt(a, xi, TTL - 1));
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

	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	long long t, num, den;
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
	if ((long long)*this < 0)return rational(-1, 0);

	//return sqrt(*this, rational(1),255); //данный метод  находит корень с погрешностью +- 0.02 , что не допустимо
	// тот же метод, но работающий отдельно с числителем и знаминателем находили ответ или были близки к нему на 0.000000001 (точность для выхода из рекурсии)
	return rational(std::sqrt((double)*this));// слишком долго и не точно ( но точнее первого варианта)
}


