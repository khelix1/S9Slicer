#include "infill.h"
#include <iostream>

std::vector<Contour> InfillGenerator::generateGrid(const Contour& boundary, float spacing) {
    std::vector<Contour> lines;
    std::cout << "[InfillGenerator] Generating grid infill with spacing " << spacing << "\n";

    // Placeholder logic: create a single dummy horizontal line inside the boundary
    if (boundary.points.size() < 2) return lines;

    double y_min = boundary.points[0].y;
    double y_max = boundary.points[0].y;
    double x_min = boundary.points[0].x;
    double x_max = boundary.points[0].x;

    for (const auto& pt : boundary.points) {
        if (pt.y < y_min) y_min = pt.y;
        if (pt.y > y_max) y_max = pt.y;
        if (pt.x < x_min) x_min = pt.x;
        if (pt.x > x_max) x_max = pt.x;
    }

    for (double y = y_min; y <= y_max; y += spacing) {
        Contour line;
        line.points.push_back(Point(x_min, y));
        line.points.push_back(Point(x_max, y));
        lines.push_back(line);
    }

    return lines;
}
