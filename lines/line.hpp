#ifndef MATHLINE_HPP
#define MATHLINE_HPP

#include "../color.hpp"
#include "../imageSettings.hpp"
#include "../point.hpp"

using ColorRow = std::vector<Color>;

class Line {
   public:
    explicit Line(Point2<int> const& startPoint, Color const& color);
    void updateNextPoint(ImageSettings const& is);
    double computeXGivenY(int y, ImageSettings const& is);
    void colorRowForLine(int y, ColorRow& colorRow, ImageSettings const& is);

    virtual ~Line() = default;

   private:
    virtual void afterUpdateNextPoint() {}
    virtual double formulaForX(int y, ImageSettings const& is) = 0;
    Point2<int> const getRandomNextPoint(ImageSettings const& is);

    void adaptedXiaolinWuAttempt(int y, ColorRow& colorRow,
                                 ImageSettings const& is);
    void aliasedDrawing(int y, ColorRow& colorRow, ImageSettings const& is);

   protected:
    Point2<int> startPoint_;
    Point2<int> endPoint_;
    Color color_;
};

#endif