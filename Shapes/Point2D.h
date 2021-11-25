#pragma once
class Point2D
{
	double x, y;
	public:
		Point2D();
		Point2D(double x1, double y1);
		Point2D(const Point2D& pt);
		double Distance(const Point2D pt);
		double getX();
		double getY();

};

