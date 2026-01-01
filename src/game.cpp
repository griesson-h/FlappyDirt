#include "game.h"
#include <nlohmann/json.hpp>
#include <raylib.h>
#include "background.h"
#include "flappy.h"
#include "ground.h"
#include "pipes.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>

bool WindowCloseRequest = false;
bool HideHitboxes = true;
float GameVelocity = 100.0f;
nlohmann::json settings;

void FlappyDirt::start() {
  init();
  GameLoop();
  exit();
}

void FlappyDirt::init() {
  InitWindow(WIDTH, HEIGHT, "FlappyDirt");
  SetTargetFPS(-1);
  SetExitKey(-1);
  readsettings();

  GameVelocity = 100.0f;
  flappy = new Flappy;
  ground.resize(20);
  for (int i = 0; i < ground.size(); i++) {
    ground[i] = new Ground(i*80, HEIGHT-120);
  }
  background = new Background;
  for (int i = 0; i < pipes.size(); ++i) pipes[i] = new Pipes(WIDTH + 320*i);
}

void FlappyDirt::GameLoop() {
  while (!WindowShouldClose() && !WindowCloseRequest) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    background->drawself();
    flappy->drawself();
    for (int i = 0; i < pipes.size(); ++i) pipes[i]->drawself();
    for (auto groundtexture : ground) groundtexture->drawself();
    DrawFPS(WIDTH-100, 30);
    EndDrawing();

    flappy->Update();
    for (auto groundtexture : ground) groundtexture->Update();
    background->Update();
    for (int i = 0; i < pipes.size(); ++i) pipes[i]->Update();

    flappy->GetInput();
    for (int i = 0; i < pipes.size(); ++i) {
      if (CheckCollisionRecs(flappy->CollisionShape, pipes[i]->Collisions[1]) || CheckCollisionRecs(flappy->CollisionShape, pipes[i]->Collisions[0])) {
        flappy->GameOver();
      }
    }
    if (CheckCollisionRecs(flappy->CollisionShape, ground[0]->CollisionShape)) {
      flappy->GameOver();
    }
  }
}

void FlappyDirt::exit() {
  delete(flappy);
  for (int i = 0; i < ground.size(); ++i) delete(ground[i]); 
  for (int i = 0; i < pipes.size(); ++i) delete(pipes[i]);
  delete(background);
}

void FlappyDirt::readsettings() {
  std::stringstream raw_settings;
  std::ifstream set_fstream("res/settings.json");

  std::string s;
  while (std::getline(set_fstream, s)) {
    if (s.empty()) {
      break;
    }
    raw_settings << s << '\n';
  }
  std::cout << raw_settings.str();
  try {
    settings = nlohmann::json::parse(raw_settings.str());
  } catch(nlohmann::json::parse_error e) {
    std::stringstream error;
    error << "Settings reading error: " << e.what() << std::endl;
    throw std::runtime_error(error.str());
  }
}
