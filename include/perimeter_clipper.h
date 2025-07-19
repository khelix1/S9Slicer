#pragma once
#include "contour.h"
#include <vector>

class PerimeterClipper {
public:
    static std::vector<Contour> offsetPerimeters(const Contour& outer, double distance);
};
