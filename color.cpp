#include "color.hpp"

Color const average(Color const& l, Color const& r) {
    return Color((l.r_ + r.r_) / 2, (l.g_ + r.g_) / 2, (l.b_ + r.g_) / 2);
}

void resetColorRow(ColorRow& row, const Color& defaultColor) {
    for (auto& r : row) {
        r = std::move(Color(defaultColor));
    }
}