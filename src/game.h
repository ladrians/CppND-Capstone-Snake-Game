#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"

class Game {
 public:
  Game();
  Game(std::size_t grid_width, std::size_t grid_height);
  ~Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  Game(const Game &source);
  Game &operator=(const Game &source);
  Game(Game &&source);
  Game &operator=(Game &&source);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Food food;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif