#pragma once
#include <raylib.h>
#include <stdfloat>
#include <type_traits>
#include <cstdint>

class GameObject {
  public:
    virtual void drawself();
    virtual void Update();
    virtual ~GameObject();
    Vector2 pos;
    float rot;
    float velocity;
    float acceleration;
    Rectangle CollisionShape;
};
