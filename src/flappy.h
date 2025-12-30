#pragma once
#include "object.h"
#include <raylib.h>
#include <cstdint>

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
    float RotationAcceleration;
    Texture2D texture;
    Image image;
    Rectangle SrcRec;
    Rectangle DestRec;
    Vector2 origin;
};
