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
  acceleration = 50;
  pos.x = 0;
  pos.y = 0;
}

void Background::Update() {
  if (MovedPixels >= 1200) {
    pos.x += 1200;
    MovedPixels = GetFrameTime() * acceleration;
  }
  pos.x -= GetFrameTime() * acceleration;
  MovedPixels += GetFrameTime() * acceleration;
}

Background::~Background() {
  UnloadImage(background_img);
  for (auto texture : background_txr) UnloadTexture(texture);
}
