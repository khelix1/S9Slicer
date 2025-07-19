#pragma once
#include "contour.h"
#include <vector>

class SkinGenerator {
public:
    static std::vector<Contour> generateTopSkin(const std::vector<Contour>& perimeters, float spacing);
    static std::vector<Contour> generateBottomSkin(const std::vector<Contour>& perimeters, float spacing);
};
