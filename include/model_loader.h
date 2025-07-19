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
    bool loadFromSTL(const std::string& path);
    std::vector<Contour> sliceAtZ(float z) const;
    float getMaxZ() const;

private:
    std::vector<Triangle> triangles;
};
