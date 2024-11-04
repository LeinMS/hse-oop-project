// triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3, const Color& color);

private:
    void calculatePoints(const Point& p1, const Point& p2, const Point& p3);
};

#endif // TRIANGLE_H
