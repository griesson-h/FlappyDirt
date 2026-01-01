#include "ground.h"
#include "game.h"
#include <raylib.h>

void Ground::drawself() {
  if (!HideHitboxes) DrawRectangleRec(CollisionShape, RED);
  DrawTexture(texture, pos.x, pos.y, WHITE);
}

Ground::Ground(int width, int height) {
  image = LoadImage("res/ground.png");
  ImageResizeNN(&image, 84, 160);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  pos.x = width;
  pos.y = height;
  velocity = settings["GameVelocity"];
  MovedPixels = 0.0f;
  CollisionShape = {
    0,
    HEIGHT-120,
    WIDTH,
    140
  };
}

void Ground::Update() {
  if (MovedPixels >= 80) {
    pos.x += 80;
    MovedPixels = 0.0f;
  }
  pos.x -= GetFrameTime()*velocity;
  MovedPixels += GetFrameTime()*velocity;
}

Ground::~Ground() {
  UnloadTexture(texture);
}
