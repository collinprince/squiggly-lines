#include "line.hpp"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

Line::Line(Point2 const& startPoint, Color const& color)
    : startPoint_(startPoint), endPoint_(startPoint), color_(color) {}

void Line::updateNextPoint(ImageSettings const& is) {
    // first update endPoint_ to be new startPoint_
    startPoint_ = endPoint_;

    Point2 nextPoint(getRandomNextPoint(is));
    // map this line as a straight line with formula: x = slope_ * y +
    // nextPoint.x()

    endPoint_ = nextPoint;
    afterUpdateNextPoint();
}

int Line::computeXGivenY(int y, ImageSettings const& is) {
    return formulaForX(y, is);
}

void Line::colorRowForLine(int y, ColorRow& colorRow, ImageSettings const& is) {
    int x = computeXGivenY(y, is);
    colorRow[x] = color_;
}

Point2 const Line::getRandomNextPoint(ImageSettings const& is) {
    // nextX is in range [-maxChangeInX, +maxChangeInX]
    int nextX = startPoint_.x() + (rand() % (2 * is.maxChangeInX() + 1)) -
                is.maxChangeInX();
    int nextY = std::min(startPoint_.y() + is.changeInY(), is.maxY());
    return Point2(nextX, nextY);
}