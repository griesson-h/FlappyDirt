#include "pipes.h"
#include "game.h"
#include <iostream>
#include <raylib.h>
#include <random>

#include <nlohmann/json.hpp>

void Pipes::drawself() {
  for (int i = 0; i < DuoPipe.size(); ++i) {
    DrawTexture(DuoPipe[i].txr, DuoPipe[i].pos.x, DuoPipe[i].pos.y, DuoPipe[i].color);
  }
  if (!HideHitboxes) {
    DrawRectangleRec(Collisions[0], RED);
    DrawRectangleRec(Collisions[1], RED);
  }
}

Pipes::Pipes(float x) {
  pipe_img = LoadImage("res/pipe.png");
  ImageResizeNN(&pipe_img, 160, 640);
  pipe_txr_down = LoadTextureFromImage(pipe_img);
  ImageRotate(&pipe_img, 180);
  pipe_txr_up = LoadTextureFromImage(pipe_img);

  GapBetweenPipes = 160;
  velocity = settings["GameVelocity"];
  RegenerateHeight(x);
}

void Pipes::Update() {
  if (DuoPipe[0].pos.x <= -pipe_txr_down.width) {
    RegenerateHeight(WIDTH + pipe_txr_down.height);
  }
  DuoPipe[0].pos.x = DuoPipe[1].pos.x -= GetFrameTime() * velocity;

  Collisions[0] = {
    DuoPipe[0].pos.x + 45,
    DuoPipe[0].pos.y,
    70,
    640
  };
  Collisions[1] = {
    DuoPipe[1].pos.x + 45,
    DuoPipe[1].pos.y,
    70,
    640
  };
}

Pipes::~Pipes() {
  UnloadImage(pipe_img);
}

void Pipes::RegenerateHeight(float x) {
  std::random_device ran_d;
  std::mt19937 mt(ran_d());
  std::uniform_real_distribution<float> dist_pos(100.0f, HEIGHT - 50 - GapBetweenPipes);
  std::uniform_real_distribution<float> dist_color(0, 255);

  Color RanColor;
  RanColor = Color(dist_color(mt), dist_color(mt), dist_color(mt), 255);

  float RanHeight = 0.0f;
  RanHeight = dist_pos(mt);
  Pipe BottomPipe = {
      pipe_txr_down,
      {x, RanHeight},
      RanColor
  };
  Pipe TopPipe = {
      pipe_txr_up,
      {x, RanHeight - GapBetweenPipes - pipe_txr_up.height},
      RanColor
  };
  std::cout << TopPipe.pos.x << std::endl;
  DuoPipe = {
    BottomPipe,
    TopPipe
  };
}
