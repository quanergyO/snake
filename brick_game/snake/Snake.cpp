#include "Snake.h"

namespace Snake
{

Snake::Snake() : direction_(Down), coords_(3)
{
    for (size_t i = 0; i < 3; ++i) {
        coords_[i].x = 4;
        coords_[i].y = 7 - i;
    }
}

void Snake::eat()
{
    // Move once
    coords_.emplace_back(coords_.back());
}

void Snake::move(const Direction& direction)
{

}

} // namespace Snake
