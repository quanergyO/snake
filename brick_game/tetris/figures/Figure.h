#ifndef SRC_FIGURE_H
#define SRC_FIGURE_H

#include <vector>

namespace Tetris {

struct Point {
    size_t x_;
    size_t y_;
};


class Figure
{
public:
    Figure();
    ~Figure() = default;

private:
    std::vector<Point> coords_;
};

} // namespace Tetris

#endif //SRC_FIGURE_H
