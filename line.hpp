#ifndef LINE_HPP
#define LINE_HPP

#include <stdlib.h>

#include <vector>

#include "color.hpp"
#include "point.hpp"

using ColorRow = std::vector<Color>;
class Line;
bool isLineCollidingWithOtherLine(const Line& l,
                                  const std::vector<Line>& lines);

void resetColorRow(ColorRow& row, const Color& defaultColor) {
    for (auto& r : row) {
        r = std::move(Color(defaultColor));
    }
}

class Line {
   public:
    explicit Line(const Point2& startPoint, const Color& color, const int maxX,
                  const int maxY)
        : currentPoint_(startPoint), color_(color), maxX_(maxX), maxY_(maxY) {}

    Point2 const& currentPoint() const { return currentPoint_; }

    Point2 const computeNextPoint() const {
        // choosePoint will be either -1, 0, or 1
        int const choosePoint = (rand() % 3) - 1;

        int const nextY = currentPoint_.y();
        int nextX = currentPoint_.x();
        // if nextX + choosePoint is within bounds, update
        // else just keep nextX as the same as before
        if (nextX + choosePoint >= 0 || nextX + choosePoint <= maxX_) {
            nextX = nextX + choosePoint;
        }

        // gives lines on the edge a bit of a boost to get away
        if (nextX + choosePoint == 0) {
            nextX += 1;
        } else if (nextX + choosePoint == maxX_) {
            nextX -= 1;
        }
        return Point2(nextX, nextY);
    }

    void updatePoint(ColorRow& row, const std::vector<Line>& lines,
                     Color const& defaultColor) {
        Point2 nextPoint(computeNextPoint());
        // keep updating till we don't overwrite another color
        int maxDepth = 0;

        // try to keep lines from colliding while keeping paths random
        while (isLineCollidingWithOtherLine(*this, lines) && maxDepth < 50) {
            nextPoint = computeNextPoint();
            ++maxDepth;
        }
        // first attempt at averaged shading to make lines smoother
        if (currentPoint_.x() == nextPoint.x() + 1 ||
            currentPoint_.x() == nextPoint.x() - 1) {
            row[currentPoint_.x()] = average(color_, defaultColor);
        }
        currentPoint_ = nextPoint;

        row[nextPoint.x()] = color_;
    }

   private:
    Point2 currentPoint_;
    Color color_;
    int maxX_;
    int maxY_;
};

bool isLineCollidingWithOtherLine(const Line& l,
                                  const std::vector<Line>& lines) {
    return std::any_of(lines.begin(), lines.end(), [&l, &lines](auto const& r) {
        if (&l == &r) {
            return false;
        }
        if (l.currentPoint() == r.currentPoint()) {
            return true;
        }
        return false;
    });
}

#endif