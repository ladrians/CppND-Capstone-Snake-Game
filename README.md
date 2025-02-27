# CPPND: Capstone Snake Game

Implementation for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) Capstone project. The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

##### Behavior

When running the game, the expected behavior is to show the snake and food item on a random location; use:

* `n` to start a new game.
* `spacebar` to pause the new game.
* `x` to exit.
* `arrow keys` to move the snake towards the food item.

## Rubrik considerations

[Rubric](https://review.udacity.com/#!/rubrics/2533/view) brief review.

* Add support for smart pointers (Memory Management).
* General code refactoring
 * New `Food` class was created, accessing state via member functions (Object Oriented Programming - Classes use appropriate access specifiers for class members / Classes encapsulate behavior / ).
 * new `common` definitions to centralize random numbers generation (Object Oriented Programming - The project uses Object Oriented Programming techniques).
* Created new options to the game to `start/pause/exit` (Loops, Functions, I/O - C++ functions and control structures).
* Accumulate the scores to the `build/game_history.txt` file (Loops, Functions, I/O - The project reads data from a file and process the data, or the program writes data to a file).
 * Food class uses the current snake object (Memory Management - The project makes use of references in function declarations).

## Bonus

Created another project [Slanted Lidar](https://github.com/ladrians/CppND-Capstone) based on [ROS2 foxy](https://docs.ros.org/en/foxy/Installation.html) (which uses the C++ 14 standard) to exercise concepts of this course.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
