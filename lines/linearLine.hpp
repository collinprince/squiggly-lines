#ifndef LINEAR_LINE_HPP
#define LINEAR_LINE_HPP

#include "../imageSettings.hpp"
#include "line.hpp"

class LinearLine : public Line {
   public:
    explicit LinearLine(Point2 const&, Color const&);

   private:
    int formulaForX(int y, ImageSettings const& is) override;
};

#endif