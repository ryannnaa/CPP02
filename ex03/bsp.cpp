#include "Point.hpp"

static Fixed triArea(const Point& a, const Point& b, const Point& c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2);

    if (area < Fixed(0))
        area = area * Fixed(-1);
    return (area);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed areaABC = triArea(a, b, c);
    Fixed areaPAB = triArea(point, a, b);
    Fixed areaPBC = triArea(point, b, c);
    Fixed areaPCA = triArea(point, c, a);

    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return (false);
    return (areaPAB + areaPBC + areaPCA == areaABC);
}