#pragma once
#include "contour.h"
#include <vector>

namespace ClipperUtils {
    std::vector<Contour> offset(const Contour& input, double distance);
}
