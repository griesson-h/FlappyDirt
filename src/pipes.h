#pragma once
#include "object.h"
#include <array>
#include <raylib.h>

class Pipes : public GameObject {
  public:
    void drawself();
    void Update();
    std::array<Rectangle, 2> Collisions;
    Pipes();
    ~Pipes();
  private:
    Vector2 GetRandomPosition(int xBar, int yBar);
    Image pipe_img;
    Texture2D pipe_txr_up;
    Texture2D pipe_txr_down;
    float GapBetweenPipes;
    struct Pipe {
      Texture2D txr;
      Vector2 pos;
    };
    std::array<Pipe, 2> DuoPipe;

    void RegenerateHeight();
};
