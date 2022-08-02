#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <vector>

#include "shape.hpp"

class Rectangle : public Shape {
   public:
    explicit Rectangle(Graph const&, Color const&, GraphPoint const& topLeft,
                       double width, double height);
    explicit Rectangle(Graph const&, Color const&, GraphPoint const& topLeft,
                       GraphPoint const& bottomRight);

   private:
    GraphPoint topLeft_;
    GraphPoint bottomRight_;

    std::vector<GraphUnit> formulaForXValues(PixelUnit pixelY,
                                             ImageSettings const&) override;

    inline bool isWithinRectangleBoundary(PixelUnit pixelY);
    inline bool isOnRectangleBoundary(PixelUnit pixelY);
};

Rectangle::Rectangle(Graph const& graph, Color const& color,
                     GraphPoint const& topLeft, double width, double height)
    : Shape{graph, color},
      topLeft_{topLeft},
      bottomRight_{topLeft.x() + width, topLeft.y() + height} {}

Rectangle::Rectangle(Graph const& graph, Color const& color,
                     GraphPoint const& topLeft, GraphPoint const& bottomRight)
    : Shape{graph, color}, topLeft_{topLeft}, bottomRight_{bottomRight} {}

std::vector<Rectangle::GraphUnit> Rectangle::formulaForXValues(
    Rectangle::PixelUnit pixelY, ImageSettings const&) {
    if (isWithinRectangleBoundary(pixelY)) {
        if (isOnRectangleBoundary(pixelY)) {
            std::vector<double> ret;
            auto pixelX = graph_.convertGraphXToPixelX(topLeft_.x());
            auto rightPixelX = graph_.convertGraphXToPixelX(bottomRight_.x());
            for (; pixelX <= rightPixelX; ++pixelX) {
                ret.emplace_back(graph_.convertPixelXToGraphX(pixelX));
            }
            return ret;
        } else {
            return {topLeft_.x(), bottomRight_.x()};
        }
    }
    return {};
}

bool Rectangle::isWithinRectangleBoundary(Rectangle::PixelUnit pixelY) {
    return (pixelY >= graph_.convertGraphYToPixelY(topLeft_.y())) &&
           (pixelY <= graph_.convertGraphYToPixelY(bottomRight_.y()));
}

bool Rectangle::isOnRectangleBoundary(Rectangle::PixelUnit pixelY) {
    return (pixelY == graph_.convertGraphYToPixelY(topLeft_.y())) ||
           (pixelY == graph_.convertGraphYToPixelY(bottomRight_.y()));
}

#endif