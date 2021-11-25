#include "Point2D.h"
#include <math.h>
Point2D::Point2D()
{
	x = 0.0; y = 0.0;
}

Point2D::Point2D(double x1, double y1)
{
	x = x1; y = y1;
}

Point2D::Point2D(const Point2D& pt)
{
	x = pt.x; y = pt.y;
}

double Point2D::Distance(const Point2D pt)
{
	return sqrt((x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y));
}

double Point2D::getX()
{ return x; }

double Point2D::getY()
{
	return y;
}
