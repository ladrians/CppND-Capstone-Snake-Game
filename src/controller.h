#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  Controller();
  Controller(const Controller &source);
  Controller(Controller &&source);
  Controller &operator=(const Controller &source);
  ~Controller();
  Controller &operator=(Controller &&source);
  void HandleInput(bool &running, Snake &snake, bool &on_pause, bool &on_new_game, bool &on_exit_game) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif