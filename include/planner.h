#pragma once
#include "contour.h"
#include <vector>
#include <string>

class LayerPlan {
public:
    float z;
    std::vector<Contour> perimeters;
    std::vector<Contour> infill;
    std::vector<Contour> skin;
};

class Planner {
public:
    static std::vector<LayerPlan> buildPlan(
        const std::vector<std::vector<Contour>>& rawLayers,
        float skinSpacing,
        float infillSpacing
    );
};
