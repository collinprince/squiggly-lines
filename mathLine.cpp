#include "mathLine.hpp"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

MathLine::MathLine(Point2 const& startPoint, Color const& color)
    : slope_(0),
      startPoint_(startPoint),
      endPoint_(startPoint),
      color_(color) {}

void MathLine::updateNextPoint(ImageSettings const& is) {
    // first update endPoint_ to be new startPoint_
    startPoint_ = endPoint_;

    Point2 nextPoint(getRandomNextPoint(is));
    // map this line as a straight line with formula: x = slope_ * y +
    // nextPoint.x()

    slope_ =
        static_cast<double>((nextPoint.x() - startPoint_.x())) / is.changeInY();
    endPoint_ = nextPoint;
    afterUpdateNextPoint();
}

int MathLine::computeXGivenY(int y, ImageSettings const& is) {
    // map this line as a straight line with formula: x = slope_ * y +
    // currentPoint_.x()

    // -1 (10) +
    return formulaForX(y, is);
}

void MathLine::colorRowForLine(int y, ColorRow& colorRow,
                               ImageSettings const& is) {
    int x = computeXGivenY(y, is);
    colorRow[x] = color_;
}

Point2 const MathLine::getRandomNextPoint(ImageSettings const& is) {
    // nextX is in range [-maxChangeInX, +maxChangeInX]
    int nextX = startPoint_.x() + (rand() % (2 * is.maxChangeInX() + 1)) -
                is.maxChangeInX();
    int nextY = std::min(startPoint_.y() + is.changeInY(), is.maxY());
    return Point2(nextX, nextY);
}
void MathLine::printCurrentAndEndPoint() const {
    std::cerr << "startPoint_: " << startPoint_.x() << ", " << startPoint_.y()
              << "; endPoint_: " << endPoint_.x() << ", " << endPoint_.y()
              << '\n';
}

int MathLine::formulaForX(int y, ImageSettings const& is) {
    double slope = static_cast<double>(endPoint_.x() - startPoint_.x()) /
                   (endPoint_.y() - startPoint_.y());

    int x = slope * (y - startPoint_.y()) + startPoint_.x();
    if (x <= 0) {
        x = 1;  // made this 1 because the reflection was sort of off when it
                // was 0
        startPoint_ = Point2(x, y);
        endPoint_.setX(-endPoint_.x());
    } else if (x >= is.maxX()) {
        x = is.maxX();
        startPoint_ = Point2(x, y);
        endPoint_.setX(is.maxX() - (endPoint_.x() - is.maxX()));
    }

    return x;
}