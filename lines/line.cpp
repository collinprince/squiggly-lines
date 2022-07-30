#include "line.hpp"

#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>

Line::Line(Point2<int> const& startPoint, Color const& color)
    : startPoint_(startPoint), endPoint_(startPoint), color_(color) {}

void Line::updateNextPoint(ImageSettings const& is) {
    // first update endPoint_ to be new startPoint_
    startPoint_ = endPoint_;

    Point2<int> nextPoint(getRandomNextPoint(is));
    // map this line as a straight line with formula: x = slope_ * y +
    // nextPoint.x()

    endPoint_ = nextPoint;
    afterUpdateNextPoint();
}

double Line::computeXGivenY(int y, ImageSettings const& is) {
    return formulaForX(y, is);
}

void Line::colorRowForLine(int y, ColorRow& colorRow, ImageSettings const& is) {
    adaptedXiaolinWuAttempt(y, colorRow, is);
}

void Line::adaptedXiaolinWuAttempt(int y, ColorRow& colorRow,
                                   ImageSettings const& is) {
    auto x = computeXGivenY(y, is);

    // adaptation of xiaolin wu's line algorithm
    auto floorX = static_cast<int>(floor(x));
    auto ceilX = static_cast<int>(ceil(x));

    if (floorX == ceilX) {
        colorRow[floorX] = color_;
        return;
    }

    if (floorX >= 0) {
        if (x - floorX < 0.01) {
            colorRow[floorX] = color_;
        } else {
            colorRow[floorX] = constrain(
                average(colorRow[floorX], color_ * (1 / (x - floorX))));
        }
    }
    if (ceilX <= is.maxX()) {
        if (x - floorX > 0.99) {
            colorRow[ceilX] = color_;
        } else {
            colorRow[ceilX] =
                constrain(average(colorRow[ceilX], color_ * (1 / (ceilX - x))));
        }
    }
}

void Line::aliasedDrawing(int y, ColorRow& colorRow, ImageSettings const& is) {
    auto x = static_cast<int>(computeXGivenY(y, is));
    colorRow[x] = color_;
}

Point2<int> const Line::getRandomNextPoint(ImageSettings const& is) {
    // nextX is in range [-maxChangeInX, +maxChangeInX]
    int nextX = startPoint_.x() + (rand() % (2 * is.maxChangeInX() + 1)) -
                is.maxChangeInX();
    int nextY = std::min(startPoint_.y() + is.changeInY(), is.maxY());
    return Point2(nextX, nextY);
}