#include "Snake.h"

namespace s21 {

namespace Snake
{

Snake::Snake() : direction_(Down_s), coords_(3)
{
    for (size_t i = 0; i < 3; ++i) {
        coords_[i].x = 4;
        coords_[i].y = 7 - i;
    }
}

void Snake::eatAndMove(const UserAction_t &action)
{
    Point_t tail = coords_.back();
    move(action);
    coords_.emplace_back(tail);
}

void Snake::move(const UserAction_t &action)
{
    switch (action) {
        case Left:
        {
            moveLeft();
            break;
        }
        case Right:
        {
            moveRight();
            break;
        }
        case Up:
        {
            moveUp();
            break;
        }
        case Down:
        {
            moveDown();
            break;
        }
        default:
        {
            break;
        }
    }
}

void Snake::moveRight()
{
    if (direction_ == Left_s) {
        return;
    }
    Point_t NewPlaceForHead = {coords_[0].x + 1, coords_[0].y};
    moveTail();
    coords_[0] = NewPlaceForHead;
    direction_ = Right_s;
}

void Snake::moveLeft()
{
    if (direction_ == Right_s) {
        return;
    }
    Point_t NewPlaceForHead = {coords_[0].x - 1, coords_[0].y};
    moveTail();
    coords_[0] = NewPlaceForHead;
    direction_ = Left_s;
}

void Snake::moveUp()
{
    if (direction_ == Down_s) {
        return;
    }
    Point_t NewPlaceForHead = {coords_[0].x, coords_[0].y - 1};
    moveTail();
    coords_[0] = NewPlaceForHead;
    direction_ = Up_s;
}

void Snake::moveDown()
{
    if (direction_ == Up_s) {
        return;
    }
    Point_t NewPlaceForHead = {coords_[0].x, coords_[0].y + 1};
    moveTail();
    coords_[0] = NewPlaceForHead;
    direction_ = Down_s;
}

void Snake::moveTail()
{
    for (size_t i = coords_.size() - 1; i > 0; --i) {
        coords_[i] = coords_[i - 1];
    }
}

bool Snake::isSnakeCanEatApple(const Point_t &apple) const
{
    if (coords_[0].x == apple.x && coords_[0].y == apple.y) {
        return true;
    }
    return false;
}

bool Snake::checkIsSnakeBump() const
{
    if (coords_[0].x < 0 || coords_[0].x > 9 || coords_[0].y < 0 || coords_[0].y > 19) {
        return false;
    }
    for (size_t i = 1; i < coords_.size(); ++i) {
        if (coords_[0].x == coords_[i].x && coords_[0].y == coords_[i].y) {
            return false;
        }
    }
    return true;
}

} // namespace Snake
} // namespace s21
