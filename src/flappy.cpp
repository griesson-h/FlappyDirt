#include "flappy.h"
#include "game.h"
#include <cmath>
#include <raylib.h>
#include <iostream>

void Flappy::drawself() {
  DrawTexturePro(texture, SrcRec, DestRec, origin, rot, WHITE);
}

Flappy::Flappy() {
  image = LoadImage("res/flappy.png");
  ImageResizeNN(&image, 80, 80);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  pos.x = WIDTH*0.5-255;
  pos.y = HEIGHT*0.5-50;
  velocity = 0.0f;
  acceleration = 800.0f;
  rot = 0;

  SrcRec = {
    0,
    0,
    static_cast<float>(texture.width),
    static_cast<float>(texture.height)
  };

  origin = {40, 40};
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

  DestRec = {
    pos.x+40,
    pos.y+40,
    static_cast<float>(texture.width),
    static_cast<float>(texture.height)
  };

    if (rot < 90) {
      rot += GetFrameTime() * std::log(std::abs(velocity)) * 10;
    }
}

void Flappy::GetInput() {
  if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) Jump();
}

void Flappy::Jump() {
  rot = -20;
  velocity = -300.0f;
  acceleration = 800.0f;
}

void Flappy::GroundTouched() {
  WindowCloseRequest = true;
}

Flappy::~Flappy() {
  UnloadTexture(texture);
}
