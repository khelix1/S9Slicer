#pragma once
#include "contour.h"
#include <string>
#include <vector>

struct Triangle {
    Point v1, v2, v3;
    float zMin() const;
    float zMax() const;
};

class Model {
public:
    Model();

    // Load a model from an ASCII STL file
    bool loadFromSTL(const std::string& path);

    // Slice the model at the given Z height and return cross-section contours
    std::vector<Contour> sliceAtZ(float z) const;

    // Return the highest Z value in the model for slicing limits
    float getMaxZ() const;

    // Return number of loaded triangles
    size_t triangleCount() const;

private:
    std::vector<Triangle> triangles;
};
