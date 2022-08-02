#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "point.hpp"

// graph is an abstraction of pixelated screen,
// scaling x and y to [0, 1] range
class Graph {
   public:
    // aliases
    using PixelUnit = int;
    using GraphUnit = double;
    using PixelPoint = Point2<PixelUnit>;
    using GraphPoint = Point2<GraphUnit>;

    explicit Graph(int xMax, int yMax) : xMax_(xMax), yMax_(yMax) {}
    GraphPoint convertPixelPointToGraphPoint(PixelPoint const& p) const {
        return Point2<double>(convertPixelXToGraphX(p.x()),
                              convertPixelYToGraphY(p.y()));
    }
    PixelPoint convertGraphPointToPixelPoint(GraphPoint const& p) const {
        return Point2<int>(convertGraphXToPixelX(p.x()),
                           convertGraphYToPixelY(p.y()));
    }

    GraphUnit convertPixelXToGraphX(PixelUnit pixelX) const {
        return static_cast<double>(pixelX) / xMax_;
    }

    GraphUnit convertPixelYToGraphY(PixelUnit pixelY) const {
        return static_cast<double>(pixelY) / yMax_;
    }

    PixelUnit convertGraphXToPixelX(GraphUnit graphX) const {
        return static_cast<int>(graphX * xMax_);
    }

    PixelUnit convertGraphYToPixelY(GraphUnit graphY) const {
        return static_cast<int>(graphY * yMax_);
    }

    GraphUnit getPixelXUnitIncrement() const { return 1.0 / xMax_; }

    GraphUnit getPixelYUnitIncrement() const { return 1.0 / yMax_; }

   private:
    PixelUnit xMax_;
    PixelUnit yMax_;
};

#endif