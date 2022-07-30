#ifndef QUADRATIC_LINE_HPP
#define QUADRATIC_LINE_HPP

#include "line.hpp"
class QuadraticLine : public Line {
   public:
    QuadraticLine(Point2 const& startPoint, Color const& color);

   private:
    int sign_;
    double amplitude_;
    int formulaForX(int y, ImageSettings const& is) override;

    // make quadratic randomly +/- on each interval update
    void afterUpdateNextPoint() override;
};

#endif