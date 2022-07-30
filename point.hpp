#ifndef POINT_HPP
#define POINT_HPP

#include <vector>

template <typename T>
class Point2 {
   public:
    explicit Point2(T x, T y) : x_(x), y_(y) {}

    T const x() const { return x_; }
    T const y() const { return y_; }

    void setX(T x) { x_ = x; }
    void setY(T y) { y_ = y; }

    inline bool operator==(const Point2& rhs) const {
        return this->x_ == rhs.x_ && this->y_ == rhs.y_;
    }

   private:
    T x_;
    T y_;
};
#endif