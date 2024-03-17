#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include "../lib/defines.h"
#include "Snake.h"

namespace s21 {
    namespace Snake {


        class Model {
        public:
            Model();

            ~Model();

            void move(const UserAction_t &action);

            void sigact(const UserAction_t &action);

        private:
            bool checkIsSnakeBump();

        private:
            State_t state_;
            Point_t apple_;
            Snake snake_;
            GameInfo_t gameInfo_;
        };

    } // namespace Snake
} // namespace s21
#endif //SRC_MODEL_H
