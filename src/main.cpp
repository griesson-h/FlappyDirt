#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <raylib.h>
#include "game.h"

int main() {
  FlappyDirt game;
  try {
    game.start();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
