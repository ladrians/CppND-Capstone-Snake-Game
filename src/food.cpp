#include "food.h"
#include "common.h"
#include "SDL.h"

void Food::Place(Snake &snake) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      _pos.x = x;
      _pos.y = y;
      return;
    }
  }
};

SDL_Point Food::GetLoc() { return _pos; };