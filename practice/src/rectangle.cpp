// rectangle.cpp
#include "rectangle.h"

Rectangle::Rectangle(const Point& topLeft, int width, int height, const Color& color)
    : Shape(color) {
    calculatePoints(topLeft, width, height);
}

void Rectangle::calculatePoints(const Point& topLeft, int width, int height) {
    for (int y = topLeft.y; y < topLeft.y + height; ++y) {
        for (int x = topLeft.x; x < topLeft.x + width; ++x) {
            m_points.push_back({x, y});
        }
    }
}
