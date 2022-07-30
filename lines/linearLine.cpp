#include "linearLine.hpp"

LinearLine::LinearLine(Point2 const& p, Color const& c) : Line(p, c) {}

double LinearLine::formulaForX(int y, ImageSettings const& is) {
    double slope = static_cast<double>(endPoint_.x() - startPoint_.x()) /
                   (endPoint_.y() - startPoint_.y());

    auto x = slope * (y - startPoint_.y()) + startPoint_.x();
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