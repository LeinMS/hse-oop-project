// shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "color.h"

struct Point {
    int x;
    int y;
};

class Shape {
public:
    virtual ~Shape() { delete m_color; }
    const std::vector<Point>& getPoints() const { return m_points; }
    const Color* getColor() const { return m_color; }

protected:
    Shape(const Color& color) : m_color(color.clone()) {}

    std::vector<Point> m_points;
    Color* m_color;
};

#endif // SHAPE_H
