#pragma once
#include <raylib.h>
#include <stdfloat>
#include <type_traits>

class GameObject {
  public:
    virtual void drawself();
    virtual void Update();
    virtual ~GameObject();
    Vector2 pos;
    Vector2 rot;
    float velocity;
    float acceleration;
    Rectangle CollisionShape;
};
