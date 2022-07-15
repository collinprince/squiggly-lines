#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

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

   private:
    int r_;
    int g_;
    int b_;
};

static Color const Red = Color(255, 0, 0);
static Color const Green = Color(0, 255, 0);
static Color const Blue = Color(0, 0, 255);
static Color const White = Color(255, 255, 255);

#endif
