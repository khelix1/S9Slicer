#include "model_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>

bool Model::loadFromSTL(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[Model] Failed to open STL file: " << path << std::endl;
        return false;
    }

    std::string line;
    Triangle tri;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;

        if (token == "vertex") {
            float x, y, z;
            iss >> x >> y >> z;
            if (tri.v1.x == 0 && tri.v2.x == 0) tri.v1 = {x, y};
            else if (tri.v2.x == 0) tri.v2 = {x, y};
            else tri.v3 = {x, y};
        } else if (token == "endloop") {
            triangles.push_back(tri);
            tri = Triangle();  // Reset for next triangle
        }
    }

    std::cout << "[Model] Loaded " << triangles.size() << " triangles from STL.
";
    return !triangles.empty();
}

std::vector<Contour> Model::sliceAtZ(float z) const {
    std::vector<Contour> result;
    for (const auto& tri : triangles) {
        if (z >= tri.zMin() && z <= tri.zMax()) {
            Contour dummy;
            dummy.points.push_back(tri.v1);
            dummy.points.push_back(tri.v2);
            dummy.points.push_back(tri.v3);
            result.push_back(dummy);
        }
    }
    return result;
}

float Model::getMaxZ() const {
    float maxZ = 0.0f;
    for (const auto& tri : triangles) {
        maxZ = std::max(maxZ, tri.zMax());
    }
    return maxZ;
}

float Triangle::zMin() const {
    return std::min({v1.y, v2.y, v3.y});
}

float Triangle::zMax() const {
    return std::max({v1.y, v2.y, v3.y});
}
