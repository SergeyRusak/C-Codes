#pragma once
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
class FiguraException {};
class Figura
{
	public:
	virtual double calc_area() = 0;
	virtual double calc_perimetr() = 0;
	virtual std::string get_name() = 0;

};

