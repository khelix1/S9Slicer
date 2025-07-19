# S9Slicer

**S9Slicer** is a professional-grade open-source 3D slicing engine written in C++ for the Sunlu S9+ and other Marlin-compatible printers. It supports STL loading, Z-slicing, contour extraction, perimeters, infill, skin generation, and G-code output.

## Features
- Modular slicing engine (C++ with Clipper integration)
- Grid infill, skin generation, perimeter pathing
- G-code output with customizable header/footer
- Lightweight and fully open-source

## Structure
- `src/engine`: C++ source code for the core slicing engine
- `include/`: Header files
- `external/clipper`: ClipperLib or placeholder geometry utilities
- `docs/`: Documentation folder

## License
MIT License. See [LICENSE](LICENSE).

---

Created by [khelix1](https://github.com/khelix1).
