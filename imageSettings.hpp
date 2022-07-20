#ifndef IMAGE_SETTINGS_HPP
#define IMAGE_SETTINGS_HPP

class ImageSettings {
   public:
    explicit ImageSettings(int maxX, int maxY, int maxChangeInX, int changeInY)
        : maxX_(maxX),
          maxY_(maxY),
          maxChangeInX_(maxChangeInX),
          changeInY_(changeInY) {}

    int maxX() const { return maxX_; }
    int maxY() const { return maxY_; }
    int maxChangeInX() const { return maxChangeInX_; }
    int changeInY() const { return changeInY_; }

   private:
    int maxX_;
    int maxY_;
    int maxChangeInX_;
    int changeInY_;
};
#endif