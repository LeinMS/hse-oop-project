// triangle.cpp
#include "triangle.h"
#include <cmath>
#include <algorithm>

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3, const Color& color)
    : Shape(color) {
    calculatePoints(p1, p2, p3);
}

void Triangle::calculatePoints(const Point& p1, const Point& p2, const Point& p3) {
    // Compute bounding box
    int minX = std::min({p1.x, p2.x, p3.x});
    int maxX = std::max({p1.x, p2.x, p3.x});
    int minY = std::min({p1.y, p2.y, p3.y});
    int maxY = std::max({p1.y, p2.y, p3.y});

    // Calculate area of the triangle
    auto area = [](const Point& a, const Point& b, const Point& c) {
        return std::abs((a.x * (b.y - c.y) +
                         b.x * (c.y - a.y) +
                         c.x * (a.y - b.y)) / 2.0);
    };
    double A = area(p1, p2, p3);

    // For all pixels in bounding box
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Point p = {x, y};
            // Calculate area of sub-triangles
            double A1 = area(p, p2, p3);
            double A2 = area(p1, p, p3);
            double A3 = area(p1, p2, p);
            // Check if point is inside triangle
            if (std::abs(A - (A1 + A2 + A3)) < 0.5) {
                m_points.push_back(p);
            }
        }
    }
}
