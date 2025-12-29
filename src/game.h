#pragma once
#include <cstdint>
#include "flappy.h"
#include "ground.h"
#include <vector>

const uint32_t WIDTH = 600;
const uint32_t HEIGHT = 800;

extern bool WindowCloseRequest;

class FlappyDirt {
  public:
    void start();
  private:
    void init();
    void GameLoop();
    void exit();

    Flappy* flappy = nullptr;
    std::vector<Ground*> ground;
};
