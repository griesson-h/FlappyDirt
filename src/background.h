#pragma once
#include <array>

#include "object.h"
class Background : public GameObject {
  public:
    void drawself();
    void Update();
    Background();
    ~Background();
  private:
    Image background_img;
    std::array<Texture2D, 2> background_txr;
    float MovedPixels;
};
