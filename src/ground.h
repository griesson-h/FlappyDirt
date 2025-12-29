#pragma once
#include "object.h"
#include <raylib.h>

class Ground : public GameObject {
  public:
    void drawself();
    void Update();
    Ground(int width, int height);
    ~Ground();
  private:
    Texture2D texture;
    Image image;
    float MovedPixels;
};
