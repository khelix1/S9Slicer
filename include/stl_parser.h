#pragma once
#include <string>
#include <vector>
#include "../contour.h"

/// STLParser provides utilities for reading STL files and generating 2D slice contours.
class STLParser {
public:
    /**
     * @brief Parses an STL file and extracts 2D contours representing slices.
     *
     * This function reads either ASCII or Binary STL formats and returns a set
     * of approximate 2D contours based on triangulated surface intersections.
     * Intended for initial Z-layer slicing or projection.
     *
     * @param filename Path to the STL file.
     * @return std::vector<Contour> Flat contours derived from mesh triangles.
     */
    static std::vector<Contour> parse(const std::string& filename);
};
