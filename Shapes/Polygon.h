#pragma once
#include "Figura.h"
#include "Point2D.h"
#include <string>
#include <vector>
class Polygon :
    public Figura
{
   std::vector<Point2D> points;

public:
    Polygon() {}
    Polygon(std::vector<Point2D> pts);
    void addVertex(const Point2D pt);
    double calc_perimetr();
    double calc_area();
    std::string get_name();
};

