#pragma once
#include "contour.h"
#include <vector>

// Provides offsetting logic to generate inner/outer perimeters
class PerimeterClipper {
public:
    // Offset the input contour by a specified distance (positive = outward, negative = inward)
    static std::vector<Contour> offsetPerimeters(const Contour& outer, double distance);
};
