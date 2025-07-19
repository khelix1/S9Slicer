
#include "fan_control.h"
#include <vector>
#include <string>

class GCodeGenerator {
public:
    GCodeGenerator();
    std::vector<std::string> generateGCode();

private:
    FanControlManager fanControl;
};

GCodeGenerator::GCodeGenerator() {}

std::vector<std::string> GCodeGenerator::generateGCode() {
    std::vector<std::string> gcode_lines;
    fanControl.startNewLayer(0);

    fanControl.registerExtrusionMove(10, 10, 0.2, 0.05, 1200);
    gcode_lines.push_back("G1 X10 Y10 Z0.2 E0.05 F1200");

    fanControl.registerTravelMove(20, 20, 0.2, 1500);
    gcode_lines.push_back("G0 X20 Y20 Z0.2 F1500");

    fanControl.registerExtrusionMove(30, 20, 0.2, 0.1, 1200);
    gcode_lines.push_back("G1 X30 Y20 Z0.2 E0.1 F1200");

    fanControl.finalizeLayer();
    fanControl.applyFanLogic(gcode_lines);

    return gcode_lines;
}

#include "infill.h"

void addInfill(std::vector<std::string>& gcode, const std::vector<Contour>& contours, float spacing, float z) {
    auto lines = InfillGenerator::generateGridInfill(contours, spacing, z);
    for (const auto& line : lines) {
        gcode.push_back("G0 X" + std::to_string(line.start.x) + " Y" + std::to_string(line.start.y) + " Z" + std::to_string(z));
        gcode.push_back("G1 X" + std::to_string(line.end.x) + " Y" + std::to_string(line.end.y) + " E0.1");
    }
}
