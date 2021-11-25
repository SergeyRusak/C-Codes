#include "Polygon.h"

Polygon::Polygon(std::vector<Point2D> pts)
{
    points = pts;
}

void Polygon::addVertex(const Point2D pt)
{
    points.push_back(pt);
}

double Polygon::calc_perimetr()
{
	double perimetr = points[0].Distance(points[points.size()-1]);
	for (int i = 0; i < points.size()-1; i++)
	{
		perimetr += points[i].Distance(points[i + 1]);
	}
	return perimetr;
}

double Polygon::calc_area()
{
    int n = points.size();
    if (n < 3) return 0.0;
    double area = 0;
    double firstX, firstY, lastX, lastY, x, y, x2, y2;
    double prearea1(0), prearea2(0);
    firstX = points[0].getX();
    firstY = points[0].getY();
    x = firstX;
    y = firstY;
    for (int i = 1; i < n - 1; i++)
    {
        x2 = points[i].getX();
        y2 = points[i].getY();
        area += (x * y2 - x2 * y);
        x = x2;
        y = y2;
    }
    lastX = points[n-1].getX();
    lastY = points[n-1].getY();
    area += (x2 * lastY - y2 * lastX) + (lastX * firstY - lastY * firstX);
    area = (area < 0) ? (area / (-2)) : (area / 2);
    return area;
	
}

std::string Polygon::get_name()
{
    return "Polygon with " + std::to_string(points.size()) + " vertexes ";
}
