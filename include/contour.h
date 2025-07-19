#pragma once
#include <vector>
#include <cmath>
#include <ostream>

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    bool operator==(const Point& other) const {
        return std::fabs(x - other.x) < 1e-6 && std::fabs(y - other.y) < 1e-6;
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }
};

class Contour {
public:
    std::vector<Point> points;

    // Compute the signed area of the contour (positive = CCW, negative = CW)
    double area() const;

    // Determine if the contour has clockwise winding
    bool isClockwise() const;

    // Close the contour if it's not closed
    void close();

    // Return true if the contour is closed
    bool isClosed() const;
};
