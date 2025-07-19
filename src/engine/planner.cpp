#include "planner.h"
#include "infill.h"
#include "skin.h"
#include <iostream>

std::vector<LayerPlan> Planner::buildPlan(
    const std::vector<std::vector<Contour>>& rawLayers,
    float skinSpacing,
    float infillSpacing
) {
    std::vector<LayerPlan> plans;

    float z = 0.0f;
    for (const auto& layerContours : rawLayers) {
        LayerPlan plan;
        plan.z = z;
        plan.perimeters = layerContours;
        plan.infill = InfillGenerator::generateGrid(layerContours[0], infillSpacing);
        plan.skin = SkinGenerator::generateTopSkin(layerContours, skinSpacing);
        plans.push_back(plan);
        z += 0.2f; // fixed layer height for now
    }

    std::cout << "[Planner] Created " << plans.size() << " layer plans\n";
    return plans;
}
