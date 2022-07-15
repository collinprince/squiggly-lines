#ifndef POINT_HPP
#define POINT_HPP

#include <vector>

class Point2 {
   public:
    explicit Point2(int x, int y) : x_(x), y_(y) {}

    int const x() const { return x_; }
    int const y() const { return y_; }

    inline bool operator==(const Point2& rhs) const {
        return this->x_ == rhs.x_ && this->y_ == rhs.y_;
    }

   private:
    int x_;
    int y_;
};

#endif