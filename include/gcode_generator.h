#pragma once
#include "contour.h"
#include <vector>
#include <string>
#include <fstream>

class GCodeGenerator {
public:
    GCodeGenerator();
    void setOutputFile(const std::string& path);
    void emitHeader();
    void emitLayer(const std::vector<Contour>& layer, float z);
    void emitFooter();

private:
    std::ofstream out;
    float currentZ;
};
