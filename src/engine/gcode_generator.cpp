#include "gcode_generator.h"
#include <sstream>
#include <iomanip>

std::string GCodeGenerator::generate(const std::vector<Contour>& paths) {
    std::ostringstream gcode;

    gcode << "; --- Begin Toolpath G-code ---\n";
    gcode << "G21 ; Set units to millimeters\n";
    gcode << "G90 ; Use absolute positioning\n";

    for (const auto& contour : paths) {
        if (contour.points.empty()) continue;

        const Point& start = contour.points.front();
        gcode << std::fixed << std::setprecision(3);
        gcode << "G0 X" << start.x << " Y" << start.y << " ; Travel move\n";

        for (size_t i = 1; i < contour.points.size(); ++i) {
            const Point& pt = contour.points[i];
            gcode << "G1 X" << pt.x << " Y" << pt.y << " ; Linear move\n";
        }

        gcode << "\n";
    }

    gcode << "; --- End Toolpath G-code ---\n";
    return gcode.str();
}
