#pragma once
#include <string>
#include <vector>
#include "../contour.h"

/// GCodeGenerator converts toolpath contours into Marlin-compatible G-code strings.
class GCodeGenerator {
public:
    /**
     * @brief Generate a basic G-code path from a series of 2D contours.
     *
     * Each contour is treated as a continuous motion path, with G0 travel to the
     * starting point and G1 movements for all following points. Output assumes
     * movements in the XY plane. Z-height and extrusion must be handled externally.
     *
     * This is a geometric motion-only generator: it does not manage fans, temperatures,
     * extrusion volume, or firmware setup commands.
     *
     * @param paths A vector of Contour objects representing XY toolpaths.
     * @return std::string Complete G-code sequence (multi-line).
     */
    static std::string generate(const std::vector<Contour>& paths);
};
