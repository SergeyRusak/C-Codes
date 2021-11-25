#include "Triangle.h"

Triangle::Triangle(double c1, double c2, double c3)
{
	if (c1<=0||c2<=0||c3<=0) throw FiguraException();
	if (c1 + c2 <= c3 || c2 + c3 <= c1 || c3 + c1 <= c2) throw TriangleException();
	else   a = c1; b = c2; c = c3;
}

double Triangle::calc_perimetr()
{
	return a + b + c;
}

double Triangle::calc_area()
{
	double p = (a + b + c) / 2.0; return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

std::string Triangle::get_name()
{
	return "Triangle";
}
