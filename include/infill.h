#pragma once
#include "contour.h"
#include <vector>

class InfillGenerator {
public:
    static std::vector<Contour> generateGrid(const Contour& boundary, float spacing);
};
