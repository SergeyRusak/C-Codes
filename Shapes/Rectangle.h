#pragma once
#include "Figura.h"

class Rectangle :
    public Figura
{
    double a, b;

public:
    Rectangle(double h, double v) { a = h; b = v; }
    double calc_area() { return a * b; }
    double calc_perimetr() { return 2 *(a + b); }
    std::string get_name() { return "Rectangle"; }
};

