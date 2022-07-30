#ifndef LINEAR_LINE_HPP
#define LINEAR_LINE_HPP

#include "../imageSettings.hpp"
#include "line.hpp"

class LinearLine : public Line {
   public:
    explicit LinearLine(Point2<int> const&, Color const&);

   private:
    double formulaForX(int y, ImageSettings const& is) override;
};

#endif