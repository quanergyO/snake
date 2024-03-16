#ifndef C7_BRICKGAME_V1_0_1_DEFINES_H
#define C7_BRICKGAME_V1_0_1_DEFINES_H

#include <cstddef>

const size_t ROWS = 20;
const size_t COLS = 10;

typedef struct {
    size_t x;
    size_t y;
} Point_t;

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action,
  Nosig
} UserAction_t;

typedef enum { START, SPAWN, MOVING, SHIFTING, ATTACHING, GAME_OVER } State_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif  // C7_BRICKGAME_V1_0_1_DEFINES_H
