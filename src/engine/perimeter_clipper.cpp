#include "perimeter_clipper.h"
#include "clipper.h"

std::vector<Contour> PerimeterClipper::offsetPerimeters(const Contour& outer, double distance) {
    return ClipperUtils::offset(outer, distance);
}
