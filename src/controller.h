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
  void HandleInput(bool &running, Snake &snake) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif