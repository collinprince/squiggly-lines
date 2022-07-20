#ifndef MATHLINE_HPP
#define MATHLINE_HPP

#include "color.hpp"
#include "imageSettings.hpp"
#include "point.hpp"

using ColorRow = std::vector<Color>;

class MathLine {
   public:
    explicit MathLine(Point2 const& startPoint, Color const& color);
    void updateNextPoint(ImageSettings const& is);
    int computeXGivenY(int y, ImageSettings const& is);
    void colorRowForLine(int y, ColorRow& colorRow, ImageSettings const& is);

    void printCurrentAndEndPoint() const;

   private:
    virtual void afterUpdateNextPoint() {}
    virtual int formulaForX(int y, ImageSettings const& is);
    Point2 const getRandomNextPoint(ImageSettings const& is);

    double slope_;

   protected:
    Point2 startPoint_;
    Point2 endPoint_;
    Color color_;
};

#endif