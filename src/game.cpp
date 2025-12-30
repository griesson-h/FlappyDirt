#include "game.h"
#include <raylib.h>
#include "background.h"
#include "flappy.h"
#include "ground.h"
#include <iostream>
#include "pipes.h"

bool WindowCloseRequest = false;
bool HideHitboxes = true;

void FlappyDirt::start() {
  init();
  GameLoop();
  exit();
}

void FlappyDirt::init() {
  InitWindow(WIDTH, HEIGHT, "FlappyDirt");
  SetTargetFPS(-1);
  SetExitKey(-1);
  flappy = new Flappy;
  ground.resize(20);
  for (int i = 0; i < ground.size(); i++) {
    ground[i] = new Ground(i*80, HEIGHT-120);
  }
  background = new Background;
  pipes = new Pipes;
}

void FlappyDirt::GameLoop() {
  while (!WindowShouldClose() && !WindowCloseRequest) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    background->drawself();
    flappy->drawself();
    pipes->drawself();
    for (auto groundtexture : ground) groundtexture->drawself();
    DrawFPS(WIDTH-100, 30);
    EndDrawing();

    flappy->Update();
    for (auto groundtexture : ground) groundtexture->Update();
    background->Update();
    pipes->Update();

    flappy->GetInput();
    if (CheckCollisionRecs(flappy->CollisionShape, ground[0]->CollisionShape) || CheckCollisionRecs(flappy->CollisionShape, pipes->Collisions[0])
        || CheckCollisionRecs(flappy->CollisionShape, pipes->Collisions[1])) {
      flappy->GameOver();
    }
  }
}

void FlappyDirt::exit() {
  delete(flappy);
  for (auto groundtexture : ground) delete(groundtexture);
  delete(background);
}
