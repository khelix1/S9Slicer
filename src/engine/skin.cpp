
#include "skin.h"
#include "clipper2/clipper.h"
#include <cmath>

using namespace Clipper2Lib;

PathD toClipperPath(const std::vector<glm::vec2>& loop) {
    PathD path;
    for (const auto& pt : loop) path.emplace_back(pt.x, pt.y);
    return path;
}

std::vector<glm::vec2> fromClipperPath(const PathD& path) {
    std::vector<glm::vec2> out;
    for (const auto& pt : path) out.emplace_back(pt.x, pt.y);
    return out;
}

std::vector<SkinLine> SkinGenerator::generate(const std::vector<Contour>& contours, float spacing, float z, bool isTopLayer) {
    std::vector<SkinLine> lines;

    float angle_deg = isTopLayer ? 45.0f : -45.0f;
    float angle_rad = glm::radians(angle_deg);
    glm::vec2 dir(std::cos(angle_rad), std::sin(angle_rad));
    glm::vec2 ortho(-dir.y, dir.x);

    float xmin = 1e6, xmax = -1e6, ymin = 1e6, ymax = -1e6;
    for (const auto& c : contours) {
        for (const auto& pt : c.points) {
            xmin = std::min(xmin, pt.x);
            xmax = std::max(xmax, pt.x);
            ymin = std::min(ymin, pt.y);
            ymax = std::max(ymax, pt.y);
        }
    }

    std::vector<PathD> clipPaths;
    for (const auto& c : contours)
        clipPaths.push_back(toClipperPath(c.points));

    for (float i = -1000; i < 1000; i += spacing) {
        glm::vec2 center = 0.5f * glm::vec2(xmin + xmax, ymin + ymax) + ortho * i;
        glm::vec2 p1 = center - dir * 2000.0f;
        glm::vec2 p2 = center + dir * 2000.0f;

        PathD skinLine = {{p1.x, p1.y}, {p2.x, p2.y}};
        Clipper64 clip;
        clip.AddPath(skinLine, PathType::Subject, false);
        clip.AddPaths(clipPaths, PathType::Clip, true);
        Paths64 result = clip.Execute(ClipType::Intersection, FillRule::NonZero);

        for (const auto& seg : result) {
            if (seg.size() >= 2) {
                for (size_t j = 0; j + 1 < seg.size(); ++j)
                    lines.push_back({glm::vec2(seg[j].x, seg[j].y), glm::vec2(seg[j + 1].x, seg[j + 1].y)});
            }
        }
    }

    return lines;
}
