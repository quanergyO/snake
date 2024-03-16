#ifndef SRC_SNAKE_H
#define SRC_SNAKE_H

#include "../lib/defines.h"
#include <vector>

namespace Snake
{

class Snake {
    enum Direction {
        Up,
        Down,
        Left,
        Rigth,
        Nosig
    };

public:
    Snake();
    ~Snake() = default;
    void eat();
    void move(const Direction& direction = Nosig);

private:
    Direction direction_;
    std::vector<Point_t> coords_;
};

} // namespace Snake

#endif //SRC_SNAKE_H
