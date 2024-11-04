// circle.cpp
#include "circle.h"
#include <cmath>

Circle::Circle(const Point& center, int radius, const Color& color)
    : Shape(color) {
    calculatePoints(center, radius);
}

void Circle::calculatePoints(const Point& center, int radius) {
    int rSquared = radius * radius;
    for (int y = center.y - radius; y <= center.y + radius; ++y) {
        for (int x = center.x - radius; x <= center.x + radius; ++x) {
            int dx = x - center.x;
            int dy = y - center.y;
            if (dx * dx + dy * dy <= rSquared) {
                m_points.push_back({x, y});
            }
        }
    }
}
