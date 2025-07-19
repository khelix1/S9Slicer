#include "perimeter_clipper.h"
#include "clipper.h"
#include <iostream>

std::vector<Contour> PerimeterClipper::offsetPerimeters(const Contour& outer, double distance) {
    if (!outer.isClosed()) {
        std::cerr << "[PerimeterClipper] Warning: input contour not closed. Auto-closing.\n";
        Contour closed = outer;
        closed.close();
        return ClipperUtils::offset(closed, distance);
    }

    std::cout << "[PerimeterClipper] Offsetting contour with distance: " << distance << "\n";
    return ClipperUtils::offset(outer, distance);
}
