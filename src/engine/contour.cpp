#include "contour.h"

double Contour::area() const {
    double a = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % points.size()];
        a += (p1.x * p2.y - p2.x * p1.y);
    }
    return a * 0.5;
}

bool Contour::isClockwise() const {
    return area() < 0.0;
}
