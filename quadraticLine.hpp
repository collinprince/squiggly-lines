#ifndef QUADRATIC_LINE_HPP
#define QUADRATIC_LINE_HPP

#include "mathLine.hpp"
class QuadraticLine : public MathLine {
   public:
    QuadraticLine(Point2 const& startPoint, Color const& color)
        : MathLine(startPoint, color), sign_(1), amplitude_(1 / 50.0) {}

   private:
    int sign_;
    double amplitude_;
    int formulaForX(int y, ImageSettings const& is) override {
        // treat startPoint_ and endPoint_ as y intercepts for quadratic formula
        // x = a*y^2 + b*y + c -> x = (y - y0) * (y - y1) + x0

        int x = static_cast<double>(sign_ * amplitude_ * (y - startPoint_.y()) *
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

    // make quadratic randomly +/- on each interval update
    void afterUpdateNextPoint() override {
        endPoint_.setX(startPoint_.x());  // for quadratic, we want the x values
                                          // to be the same for start and end
        sign_ = rand() % 2 == 0 ? 1 : -1;
        // get random variance in [-20, 20]
        int maxVariance = 30;
        int randomAmplitudeVariance =
            (rand() % (maxVariance * 2 + 1)) - maxVariance;
        amplitude_ = 1 / (50.0 + static_cast<double>(randomAmplitudeVariance));
    }
};

#endif