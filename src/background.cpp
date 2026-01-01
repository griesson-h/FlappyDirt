#include "background.h"
#include "game.h"
#include <raylib.h>

void Background::drawself() {
  for (int i = 0; i < 2; i++)
    DrawTexture(background_txr[i], (i * background_txr[i].width) + pos.x, pos.y, WHITE);
}

Background::Background() {
  background_img = LoadImage("res/background.png");
  ImageResizeNN(&background_img, 1200, 900);
  for (int i = 0; i < 2; i++) background_txr[i] = LoadTextureFromImage(background_img);
  velocity = static_cast<float>(settings["GameVelocity"])/2;
  pos.x = 0;
  pos.y = 0;
  MovedPixels = 0;
}

void Background::Update() {
  if (MovedPixels >= 1200) {
    pos.x += 1200;
    MovedPixels = GetFrameTime() * velocity;
  }
  pos.x -= GetFrameTime() * velocity;
  MovedPixels += GetFrameTime() * velocity;
}

Background::~Background() {
  UnloadImage(background_img);
  for (auto texture : background_txr) UnloadTexture(texture);
}
