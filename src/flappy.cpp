#include "flappy.h"
#include "game.h"
#include <raylib.h>

void Flappy::drawself() {
  DrawTexture(texture, pos.x, pos.y, WHITE);
}

Flappy::Flappy() {
  image = LoadImage("res/flappy.png");
  ImageResizeNN(&image, 80, 80);
  texture = LoadTextureFromImage(image);
  pos.x = WIDTH*0.5-255;
  pos.y = HEIGHT*0.5-50;
  velocity = 0.0f;
  acceleration = 800.0f;
}

void Flappy::Update() {
  velocity += GetFrameTime()*acceleration;
  pos.y += GetFrameTime()*velocity;
  CollisionShape = {
    pos.x,
    pos.y,
    80,
    60
  };
}

void Flappy::GetInput() {
  if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) Jump();
}

void Flappy::Jump() {
  velocity = -300.0f;
  acceleration = 800.0f;
}

void Flappy::GroundTouched() {
  WindowCloseRequest = true;
}

Flappy::~Flappy() {
  UnloadImage(image);
  UnloadTexture(texture);
}
