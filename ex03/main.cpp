#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

void test(const Point& a, const Point& b, const Point& c, const Point& p) {
    std::cout << "Testing point (" << p.getX().toFloat() << ", " << p.getY().toFloat() << "): ";
    if (bsp(a, b, c, p))
        std::cout << "Inside ✅" << std::endl;
    else
        std::cout << "Not inside ❌" << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    std::cout << "Triangle: A(0,0), B(4,0), C(2,3)" << std::endl << std::endl;

    Point inside(2, 1);
    test(a, b, c, inside);

    Point onEdgeAB(2, 0);
    test(a, b, c, onEdgeAB);

    Point onEdgeBC(3, 1.5);
    test(a, b, c, onEdgeBC);

    Point onEdgeCA(1, 1.5);
    test(a, b, c, onEdgeCA);

    Point onVertexA(0, 0);
    test(a, b, c, onVertexA);

    Point outside(5, 5);
    test(a, b, c, outside);

    return 0;
}