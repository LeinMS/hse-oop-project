// circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle(const Point& center, int radius, const Color& color);

private:
    void calculatePoints(const Point& center, int radius);
};

#endif // CIRCLE_H
