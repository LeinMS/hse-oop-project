// rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(const Point& topLeft, int width, int height, const Color& color);

private:
    void calculatePoints(const Point& topLeft, int width, int height);
};

#endif // RECTANGLE_H
