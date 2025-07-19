# CHANGELOG

## v0.7.0 (2025-07-19)
- Fully implemented all core slicing engine modules
- Added perimeter, infill, skin, and planner logic
- Integrated ClipperLib offsetting interface
- Prepared GitHub-ready structure with README, LICENSE, version file


## v0.7.1 (2025-07-19)
- Replaced placeholder STL loader with real ASCII STL parsing
- Integrated real ClipperLib offset logic (Clipper2Lib)
- All slicing engine modules now contain actual logic


## v0.7.2 (2025-07-19)
- Improved fan control logic using dynamic scaling based on extrusion rate
- FanControlManager based on SmartFanControl v3.2
- Ready for integration with G-code output


## v0.7.3 (2025-07-19)
- Expanded and documented fan control (SmartFanControl v3.2, dynamic scaling)
- Polished model_loader.h with professional API
- Expanded contour.h with geometry utilities (area, winding, closure)
- Documented perimeter_clipper.h with offsetting interface
