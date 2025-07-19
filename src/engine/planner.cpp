#include "planner.h"
#include "gcode_generator.h"
#include "extruder_planner.h"
#include "skin.h"
#include <iostream>

void LayerPlanner::planLayer(const std::vector<Contour>& layerContours) {
    if (layerContours.empty()) {
        std::cerr << "[LayerPlanner] Warning: Empty layer passed to planner.\n";
        return;
    }

    std::cout << "[LayerPlanner] Planning layer with " << layerContours.size() << " contour(s).\n";

    // Example: Assume first contour is outer perimeter for this placeholder logic
    Contour outer = layerContours.front();

    // Generate top skin fill (placeholder)
    auto skinFill = SkinGenerator::generateTopSkin(outer);

    // Compute extrusion values
    auto eValues = ExtruderPlanner::computeEValues(
        skinFill,    // toolpath input
        0.4,         // nozzle width mm
        0.2,         // layer height mm
        1.75,        // filament diameter mm
        1.0          // extrusion multiplier
    );

    // Generate G-code (currently XY path only, no extrusion commands)
    std::string gcode = GCodeGenerator::generate(skinFill);

    // TODO: Insert Z height, E-axis into G-code output (next step)
    std::cout << gcode;
}
