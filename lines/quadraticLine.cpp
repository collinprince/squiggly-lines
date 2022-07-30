#include "quadraticLine.hpp"

QuadraticLine::QuadraticLine(Point2 const& startPoint, Color const& color)
    : Line(startPoint, color), sign_(1), amplitude_(1 / 50.0) {}

int QuadraticLine::formulaForX(int y, ImageSettings const& is) {
    // treat startPoint_ and endPoint_ as y intercepts for quadratic formula
    // x = a*y^2 + b*y + c -> x = (y - y0) * (y - y1) + x0
    auto x = static_cast<int>(sign_ * amplitude_ * (y - startPoint_.y()) *
                              (y - endPoint_.y())) +
             startPoint_.x();
    if (x <= 0) {
        x = 1;  // made this 1 because the reflection was sort of off when
        // it was 0
        startPoint_ = Point2(x, y);
        endPoint_.setX(x);
        sign_ = -1;

    } else if (x >= is.maxX()) {
        x = is.maxX();
        startPoint_ = Point2(x, y);
        endPoint_.setX(x);
        sign_ = 1;
    }
    return x;
}

void QuadraticLine::afterUpdateNextPoint() {
    endPoint_.setX(startPoint_.x());  // for quadratic, we want the x values
                                      // to be the same for start and end
    sign_ = rand() % 2 == 0 ? 1 : -1;
    // get random variance in [-20, 20]
    auto maxVariance = 30;
    auto randomAmplitudeVariance =
        (rand() % (maxVariance * 2 + 1)) - maxVariance;
    amplitude_ = 1 / (50.0 + static_cast<double>(randomAmplitudeVariance));
}