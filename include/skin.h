#pragma once
#include <vector>
#include "../contour.h"

/// SkinGenerator is responsible for creating solid fill contours at top and bottom layers.
class SkinGenerator {
public:
    /**
     * @brief Generate top skin infill patterns within a given outer contour.
     *
     * This function returns contours representing dense solid fill for top layers,
     * aligned to the surface of the model. Patterns may vary (lines, hatch, etc.).
     * Clipping and offsetting are assumed to be handled elsewhere.
     *
     * @param outer A closed outer contour for the top surface.
     * @return std::vector<Contour> Fill contours for top skin.
     */
    static std::vector<Contour> generateTopSkin(const Contour& outer);

    /**
     * @brief Generate bottom skin infill patterns within a given outer contour.
     *
     * Similar to top skin, this function produces dense fill contours that form the
     * base layers of a printed object. Can optionally vary in pattern or overlap strategy.
     *
     * @param outer A closed outer contour for the bottom surface.
     * @return std::vector<Contour> Fill contours for bottom skin.
     */
    static std::vector<Contour> generateBottomSkin(const Contour& outer);
};
