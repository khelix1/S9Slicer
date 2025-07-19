#include "model_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool Model::loadFromSTL(const std::string& path) {
    // Simulated STL loader - no real geometry loaded yet
    std::cout << "[Model] Pretending to load STL: " << path << std::endl;
    return true;
}

std::vector<Contour> Model::sliceAtZ(float z) const {
    std::vector<Contour> slices;
    // Simulated slice: empty output
    std::cout << "[Model] Simulated slice at Z=" << z << std::endl;
    return slices;
}

float Model::getMaxZ() const {
    return 10.0f; // Simulated height
}

float Triangle::zMin() const {
    return std::min({v1.y, v2.y, v3.y});
}

float Triangle::zMax() const {
    return std::max({v1.y, v2.y, v3.y});
}
