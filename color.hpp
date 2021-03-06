#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <vector>

#include "point.hpp"

class Color {
   public:
    explicit Color(int r = 0, int g = 0, int b = 0) : r_(r), g_(g), b_(b) {}

    inline std::string const toPPMLine() const {
        return std::string(std::to_string(r_) + ' ' + std::to_string(g_) + ' ' +
                           std::to_string(b_) + '\n');
    }

    bool operator==(const Color& rhs) const {
        return r_ == rhs.r_ && g_ == rhs.g_ && b_ == rhs.b_;
    }

    bool operator!=(const Color& rhs) const { return !(*this == rhs); }

    const Color operator*(double rhs) const {
        return Color(r_ * rhs, g_ * rhs, b_ * rhs);
    }

    const Color operator/(double rhs) const { return *this * (1.0 / rhs); }

    friend Color const average(Color const& l, Color const& r);
    friend Color constrain(Color const& c);

   private:
    int r_;
    int g_;
    int b_;
};

using ColorRow = std::vector<Color>;
Color const average(Color const& l, Color const& r);
void resetColorRow(ColorRow& row, const Color& defaultColor);

static Color const Red = Color(180, 0, 0);
static Color const Green = Color(0, 180, 0);
static Color const Blue = Color(0, 0, 180);
static Color const White = Color(255, 255, 255);
static Color const Black = Color(0, 0, 0);

#endif
