
#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

struct Triangle {
    glm::vec3 normal;
    glm::vec3 v1, v2, v3;
};

class STLLoader {
public:
    bool load(const std::string& filename);
    const std::vector<Triangle>& getTriangles() const;

private:
    std::vector<Triangle> triangles;
    bool loadASCII(const std::string& filename);
    bool loadBinary(const std::string& filename);
};
