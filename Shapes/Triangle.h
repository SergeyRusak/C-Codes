#pragma once
#include "Figura.h"
#include <math.h>
class TriangleException {};
class Triangle :
    public Figura
{
    double a, b, c;

public:
    Triangle(double c1, double c2, double c3);
    double calc_perimetr();
    double calc_area();
    std::string get_name();
};


