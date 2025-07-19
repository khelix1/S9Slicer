#include "skin.h"
#include <iostream>

std::vector<Contour> SkinGenerator::generateTopSkin(const std::vector<Contour>& perimeters, float spacing) {
    std::vector<Contour> skinLines;
    std::cout << "[SkinGenerator] Generating top skin with spacing " << spacing << "\n";

    // Placeholder: simulate a few horizontal lines
    for (const auto& contour : perimeters) {
        if (contour.points.empty()) continue;
        double y = contour.points[0].y;
        Contour line;
        line.points.push_back(Point(contour.points[0].x, y));
        line.points.push_back(Point(contour.points.back().x, y));
        skinLines.push_back(line);
    }

    return skinLines;
}

std::vector<Contour> SkinGenerator::generateBottomSkin(const std::vector<Contour>& perimeters, float spacing) {
    std::vector<Contour> skinLines;
    std::cout << "[SkinGenerator] Generating bottom skin with spacing " << spacing << "\n";

    // Same placeholder logic as top skin for now
    return generateTopSkin(perimeters, spacing);
}
