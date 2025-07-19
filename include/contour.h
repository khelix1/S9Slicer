#pragma once
#include <vector>
#include <cmath>

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }
};

class Contour {
public:
    std::vector<Point> points;

    double area() const;
    bool isClockwise() const;
};
