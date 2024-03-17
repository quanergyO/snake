#include "Model.h"

namespace s21 {
    namespace Snake {

        Model::Model()
                : state_(START), snake_(), gameInfo_() {
            size_t i = 0;
            gameInfo_.field = new int *[ROWS]();
            try {
                for (; i < ROWS; ++i) {
                    gameInfo_.field[i] = new int[COLS];
                }
            } catch (...) {
                for (size_t j = 0; j < i; ++j) {
                    delete[] gameInfo_.field[j];
                }
                delete[] gameInfo_.field;
            }

            gameInfo_.score = 0;
            gameInfo_.high_score = 0; // TODO Load from file
            gameInfo_.level = 1;
            gameInfo_.speed = 1;
            gameInfo_.pause = 0;
        }

        Model::~Model() {
            delete[] gameInfo_.field[0];
            delete[] gameInfo_.field;
            delete[] gameInfo_.next[0];
            delete[] gameInfo_.next;
        }

        void Model::sigact(const UserAction_t &action) {
            switch (state_) {
                case START: {
                    switch (action) {
                        case Start: {
                            state_ = SPAWN;
                            break;
                        }
                        case Terminate: {
                            state_ = GAME_OVER;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case SPAWN: {

                    break;
                }
                case MOVING: {
                    break;
                }
                case SHIFTING: {
                    break;
                }
                case ATTACHING: // using for Pause
                {
                    break;
                }
                case GAME_OVER: {
                    break;
                }
            }
        }

        void Model::move(const UserAction_t &action) {
            if (snake_.isSnakeCanEatApple(apple_)) {
                snake_.eatAndMove(action);
            } else {
                snake_.move(action);
            }
            if (snake_.checkIsSnakeBump()) {
                // TODO throw GAME OVER
            }
        }

    } // namespace Snake
} // namespace s21
