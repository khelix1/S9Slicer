#include "model_loader.h"
#include "planner.h"
#include <iostream>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: s9slicer <path_to_stl_file>" << std::endl;
        return 1;
    }

    std::string stlPath = argv[1];
    if (!std::filesystem::exists(stlPath)) {
        std::cerr << "Error: File not found: " << stlPath << std::endl;
        return 1;
    }

    // Load STL model
    Model model = ModelLoader::loadSTL(stlPath);
    if (model.triangles.empty()) {
        std::cerr << "Failed to load model." << std::endl;
        return 1;
    }

    std::cout << "[Main] Successfully loaded model with " << model.triangles.size() << " triangles.\n";

    // Placeholder: generate a dummy outer contour for demonstration
    Contour dummy;
    dummy.points = {
        {0.0, 0.0},
        {20.0, 0.0},
        {20.0, 20.0},
        {0.0, 20.0},
        {0.0, 0.0}
    };

    std::vector<Contour> layerContours = { dummy };

    // Plan layer and emit basic G-code
    LayerPlanner::planLayer(layerContours);

    std::cout << "[Main] Done.\n";
    return 0;
}
