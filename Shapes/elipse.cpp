#include "elipse.h"


Elipse::Elipse(double rh, double rv){
	if (r1 <= 0 || r2 <= 0) FiguraException();
	r1 = rh; r2 = rv;
}

double Elipse::calc_area()
{
	return M_PI * r1 * r2;
}

double Elipse::calc_perimetr()
{
	return 4 * (M_PI * r1 * r2 + r1 - r2) / (r1 + r2);
}

std::string Elipse::get_name()
{
	return "Elipse";
}
