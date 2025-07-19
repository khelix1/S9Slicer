#include "clipper.h"
#include "clipper2/clipper.h"  // Requires real Clipper2 lib
#include <iostream>

using namespace Clipper2Lib;

std::vector<Contour> ClipperUtils::offset(const Contour& input, double distance) {
    PathsD subject;
    PathD path;

    for (const auto& pt : input.points) {
        path.push_back(PointD(pt.x, pt.y));
    }
    subject.push_back(path);

    PathsD solution = InflatePaths(subject, distance, JoinType::Round, EndType::Polygon, 2.0);

    std::vector<Contour> result;
    for (const auto& sol : solution) {
        Contour c;
        for (const auto& pt : sol) {
            c.points.push_back(Point(pt.x, pt.y));
        }
        result.push_back(c);
    }

    return result;
}
