#include "game.h"
#include <iostream>
#include "SDL.h"
#include "food.h"

Game::Game(){}

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height)
{
  food.Place(snake);
}

Game::Game(const Game &source){
  snake = source.snake;
  food = source.food;
  score = source.score;
}

Game::~Game(){}

Game &Game::operator=(const Game &source){
  if(this == &source){
    return *this;
  }
  snake = source.snake;
  food = source.food;
  score = source.score;
  return *this;
}

Game::Game(Game &&source){
  snake = source.snake;
  food = source.food;
  score = source.score;

  source.snake = Snake();
 // source.food = SDL_Point();
  source.score = 0;
}

Game &Game::operator=(Game &&source){
  if(this == &source){
    return *this;
  }
  snake = source.snake;
  food = source.food;
  score = source.score;

  source.snake = Snake();
  //source.food = SDL_Point();
  source.score = 0;
  return *this;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool on_pause = false;
  bool on_new_game = false;
  bool on_exit_game = false;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, on_pause, on_new_game, on_exit_game);
    if (on_exit_game) {
      return;
    }
    if (!on_pause) {
      Update();
    }
    if (on_new_game) {
      NewGame();
      on_new_game = false;
    }
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.GetLoc().x == new_x && food.GetLoc().y == new_y) {
    score++;
    food.Place(snake);
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

void Game::NewGame() {
  snake = Snake(snake.GetGridWidth(), snake.GetGridHeight());
  food.Place(snake);
  score = 0;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }