#pragma once
#include "Figura.h"

class Rectangle :
    public Figura
{
    double a, b;

public:
    Rectangle(double h, double v);
    double calc_area();
    double calc_perimetr();
    std::string get_name();
};

