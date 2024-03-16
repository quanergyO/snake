#include "Model.h"

namespace Tetris
{

Model::Model()
    : gameInfo_()
{
    gameInfo_.field = new int**[ROWS];
    try {
        gameInfo_.field[0] = new int*[COLS];
    } catch (...) {
        delete[] gameInfo_.field;
        throw;
    }

    try {
        gameInfo_.next = new int**[ROWS];
    } catch (...) {
        delete[] gameInfo_.field[0];
        delete[] gameInfo_.field;
        throw;
    }

    try {
        gameInfo_.next[0] = new int*[COLS];
    } catch (...) {
        delete[] gameInfo_.field[0];
        delete[] gameInfo_.field;
        delete[] gameInfo_.next;
        throw;
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

} // namespace Tetris