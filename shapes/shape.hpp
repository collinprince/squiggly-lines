#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "../color.hpp"
#include "../graph.hpp"
#include "../imageSettings.hpp"

class Shape {
   public:
    explicit Shape(Graph const& graph, Color const& color)
        : graph_(graph), color_(color) {}
    virtual ~Shape() = default;

    std::vector<double> computeXValuesGivenPixelY(int y,
                                                  ImageSettings const& is) {
        return formulaForXValues(y, is);
    }
    void colorRowForShape(int pixelY, ColorRow& colorRow,
                          ImageSettings const& is) {
        auto xValues = computeXValuesGivenPixelY(pixelY, is);
        for (auto const x : xValues) {
            auto pixelX = graph_.convertGraphXToPixelX(x);
            colorRow[pixelX] = color_;
        }
    }

   private:
    virtual std::vector<double> formulaForXValues(int y,
                                                  ImageSettings const& is) = 0;

   protected:
    Graph const& graph_;
    Color color_;
};

#endif