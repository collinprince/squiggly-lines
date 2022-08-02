#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>

#include "shape.hpp"

class Circle : public Shape {
   public:
    explicit Circle(Graph const& graph, Color const& color,
                    GraphPoint const& centerPoint, double radius);

   private:
    GraphPoint centerPoint_;
    double radius_;

    std::vector<double> formulaForXValues(PixelUnit pixelY,
                                          ImageSettings const& is) override;
};

Circle::Circle(Graph const& graph, Color const& color,
               GraphPoint const& centerPoint, double radius)
    : Shape(graph, color), centerPoint_(centerPoint), radius_(radius) {}

std::vector<double> Circle::formulaForXValues(Circle::PixelUnit pixelY,
                                              ImageSettings const& is) {
    // (x - x0)^2 + (y - y0)^2 == r^2
    // r^2 - (y - y0)^2 = (x - x0)^2 --> x = x0 +/- sqrt(r^2 - (y - y0)^2)
    auto graphY = graph_.convertPixelYToGraphY(pixelY);
    auto yMinusCenter = (graphY - centerPoint_.y());
    auto radicand = radius_ * radius_ - yMinusCenter * yMinusCenter;
    if (radicand > 0.0) {
        return {centerPoint_.x() - sqrt(radicand),
                centerPoint_.x() + sqrt(radicand)};
    } else if (radicand == 0.0) {
        return {centerPoint_.x()};
    }
    return {};
}

#endif