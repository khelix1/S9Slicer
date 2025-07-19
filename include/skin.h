
#pragma once
#include "contour.h"
#include <glm/glm.hpp>
#include <vector>

struct SkinLine {
    glm::vec2 start;
    glm::vec2 end;
};

class SkinGenerator {
public:
    static std::vector<SkinLine> generate(const std::vector<Contour>& contours, float spacing, float z, bool isTopLayer);
};
