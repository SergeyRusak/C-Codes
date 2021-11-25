#pragma once
#include "Figura.h"
#include <math.h>
class Elipse :
    public Figura
{
    double r1, r2;

public:
    Elipse(double rh, double rv);
    double calc_area();
    double calc_perimetr();
    std::string get_name();
};

