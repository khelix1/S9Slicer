
#include "engine/gcode_generator.cpp"
#include <iostream>

int main() {
    GCodeGenerator generator;
    auto gcode = generator.generateGCode();
    for (const auto& line : gcode) {
        std::cout << line << std::endl;
    }
    return 0;
}
