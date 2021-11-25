#include "Rectangle.h"

Rectangle::Rectangle(double h, double v)
{
	a = h; b = v;
}

double Rectangle::calc_area()
{
	return a * b;
}

double Rectangle::calc_perimetr()
{
	return 2 * (a + b);
}

std::string Rectangle::get_name()
{
	return "Rectangle";
}
