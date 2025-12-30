#pragma once
#include <cstdint>
#include "background.h"
#include "flappy.h"
#include "ground.h"
#include "pipes.h"
#include <raylib.h>
#include <vector>

const float WIDTH = 600;
const float HEIGHT = 800;

extern bool WindowCloseRequest;
extern bool HideHitboxes;

class FlappyDirt {
  public:
    void start();
  private:
    void init();
    void GameLoop();
    void exit();

    Flappy* flappy = nullptr;
    std::vector<Ground*> ground;
    Background* background;
    Pipes* pipes;
};
