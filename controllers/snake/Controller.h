#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include "../../brick_game/snake/Model.h"

namespace s21 {
    namespace Snake {


        class Controller {
        public:
            Controller(Model &model);

            ~Controller() = default;

            void move(const UserAction_t &action);

        private:
            Model &model_;
        };

    } // namespace Snake
} // namespace s21
#endif //SRC_CONTROLLER_H
