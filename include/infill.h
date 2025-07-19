
#pragma once
#include "contour.h"
#include <glm/glm.hpp>
#include <vector>

enum class InfillType {
    Grid,
    Line
};

struct InfillLine {
    glm::vec2 start;
    glm::vec2 end;
};

class InfillGenerator {
public:
    static std::vector<InfillLine> generateInfill(const std::vector<Contour>& contours, float spacing, float z, int layer_index, InfillType type);
    static std::vector<InfillLine> generateGridInfill(const std::vector<Contour>& contours, float spacing, float z, int layer_index);
    static std::vector<InfillLine> generateLineInfill(const std::vector<Contour>& contours, float spacing, float z, float angle_deg);
};
