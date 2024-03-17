#ifndef SRC_SNAKE_H
#define SRC_SNAKE_H

#include "../lib/defines.h"
#include <vector>

namespace s21 {
    namespace Snake {

        class Snake {
            enum Direction {
                Up_s,
                Down_s,
                Left_s,
                Right_s,
            };

        public:
            Snake();

            ~Snake() = default;

            void eatAndMove(const UserAction_t &action);

            void move(const UserAction_t &action);

            bool checkIsSnakeBump() const;

            bool isSnakeCanEatApple(const Point_t &apple) const;

        private:
            void moveRight();

            void moveLeft();

            void moveUp();

            void moveDown();

            void moveTail();


        private:
            Direction direction_;
            std::vector <Point_t> coords_;
        };

    } // namespace Snake
} // namespace s21
#endif //SRC_SNAKE_H
