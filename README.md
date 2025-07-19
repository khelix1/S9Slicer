# S9Slicer

**S9Slicer** is a professional-grade 3D slicing engine built in C++ for precision control of 3D printers, including support for multi-material setups, dynamic fan control, and G-code output. Developed with modularity, clarity, and production-readiness in mind.

## Features
- STL model parsing and Z-slicing
- Perimeter generation with ClipperLib offsetting
- Grid-based infill, solid skin, and layer planning
- G-code generation with fan control (SmartFanControl v3.2)
- Modular architecture for advanced slicer logic

## Repository Structure
- `src/engine/`: Core slicing engine modules
- `include/`: Public C++ headers
- `external/`: Embedded dependencies (Clipper)
- `docs/`: Project documentation
