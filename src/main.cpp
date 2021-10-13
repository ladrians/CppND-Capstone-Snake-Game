#include <iostream>
#include <memory>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "common.h"

std::random_device dev;
std::mt19937 engine(dev());
std::uniform_int_distribution<int> random_w(0,static_cast<int>(32 - 1));
std::uniform_int_distribution<int> random_h(0,static_cast<int>(32 - 1));

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  auto game = std::make_unique<Game>(kGridWidth, kGridHeight);
  game->Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game->GetScore() << "\n";
  std::cout << "Size: " << game->GetSize() << "\n";
  // Append the game record to a file.
  std::ofstream ofs{"game_history.txt", std::ios::app};
  ofs << "Score: " << game->GetScore() << "\n";
  ofs << "Size: " << game->GetSize() << "\n";
  ofs << "\n";
  return 0;
}