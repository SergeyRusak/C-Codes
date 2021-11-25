// findArea.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Figura.h"
#include "Rectangle.h"
#include "Elipse.h"
#include "Triangle.h"
#include "Polygon.h"

int main()
{
    std::vector<Figura*> shapes;
    Rectangle r(5, 2);
    shapes.push_back(&r);
    Elipse e(2, 10);
    shapes.push_back(&e);
    Triangle t(5, 2, 4);  
    shapes.push_back(&t);

    Polygon p;
    p.addVertex(Point2D(0, 0));
    p.addVertex(Point2D(1, 0));
    p.addVertex(Point2D(1, 1));
    p.addVertex(Point2D(0, 1));
    shapes.push_back(&p);

    std::vector<Point2D> vertex;
    vertex.push_back(Point2D(3, 4));
    vertex.push_back(Point2D(5, 11));
    vertex.push_back(Point2D(12, 8));
    vertex.push_back(Point2D(9, 5));
    vertex.push_back(Point2D(5, 6));
    Polygon g(vertex);
   shapes.push_back(&g);
    
    for(Figura* i : shapes)
    {
        std::cout << i->get_name() << std::endl <<
            "Area:" << i->calc_area() << std::endl <<
            "Perimetr:" << i->calc_perimetr() << std::endl << std::endl;

    }

    
}
