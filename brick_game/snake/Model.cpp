#include "Model.h"

namespace Snake
{

    Model::Model()
            : gameInfo_()
    {
        size_t i = 0;
        gameInfo_.field = new int*[ROWS]();
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

} // namespace Snake
