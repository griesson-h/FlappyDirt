#include "pipes.h"
#include "game.h"
#include <iostream>
#include <raylib.h>
#include <ctime>
#include <cstdlib>

void Pipes::drawself() {
  for (int i = 0; i < DuoPipe.size(); ++i) {
    DrawTexture(DuoPipe[i].txr, DuoPipe[i].pos.x, DuoPipe[i].pos.y, GREEN);
  }
  if (!HideHitboxes) {
    DrawRectangleRec(Collisions[0], RED);
    DrawRectangleRec(Collisions[1], RED);
  }
}

Pipes::Pipes() {
  pipe_img = LoadImage("res/pipe.png");
  ImageResizeNN(&pipe_img, 160, 640);
  pipe_txr_down = LoadTextureFromImage(pipe_img);
  ImageRotate(&pipe_img, 180);
  pipe_txr_up = LoadTextureFromImage(pipe_img);

  GapBetweenPipes = 160;
  velocity = 100;
  RegenerateHeight();
}

void Pipes::Update() {
  if (DuoPipe[0].pos.x <= -160) {
    RegenerateHeight();
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

void Pipes::RegenerateHeight() {
  srand(time(NULL));
  float RanHeight;
  while (RanHeight < 50) {
    RanHeight = rand() % static_cast<uint32_t>(HEIGHT - 50 - GapBetweenPipes);
  }
  Pipe BottomPipe = {
      pipe_txr_down,
      {WIDTH + pipe_txr_down.width, RanHeight}
  };
  Pipe TopPipe = {
      pipe_txr_up,
      {WIDTH + pipe_txr_down.width, RanHeight - GapBetweenPipes - pipe_txr_up.height}
  };
  std::cout << TopPipe.pos.y << std::endl;
  DuoPipe = {
    BottomPipe,
    TopPipe
  };
}
