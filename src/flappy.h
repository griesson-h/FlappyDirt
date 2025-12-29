#pragma once
#include "object.h"
#include <raylib.h>

class Flappy : public GameObject {
  public:
    void drawself();
    void Update();
    void GetInput();
    void Jump();
    void GroundTouched();
    ~Flappy();
    Flappy();
  private:
    Texture2D texture;
    Image image;
};
