#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "point.hpp"

// graph is an abstraction of pixelated screen,
// scaling x and y to [0, 1] range
class Graph {
   public:
    explicit Graph(int xMax, int yMax) : xMax_(xMax), yMax_(yMax) {}
    Point2<double> convertPixelPointToGraphPoint(Point2<int> const& p) const {
        return Point2<double>(convertPixelXToGraphX(p.x()),
                              convertPixelYToGraphY(p.y()));
    }
    Point2<int> convertGraphPointToPixelPoint(Point2<double> const& p) const {
        return Point2<int>(convertGraphXToPixelX(p.x()),
                           convertGraphYToPixelY(p.y()));
    }

    double convertPixelXToGraphX(int pixelX) const {
        return static_cast<double>(pixelX) / xMax_;
    }

    double convertPixelYToGraphY(int pixelY) const {
        return static_cast<double>(pixelY) / yMax_;
    }

    int convertGraphXToPixelX(double graphX) const {
        return static_cast<int>(graphX * xMax_);
    }

    int convertGraphYToPixelY(double graphY) const {
        return static_cast<int>(graphY * yMax_);
    }

   private:
    int xMax_;
    int yMax_;
};

#endif