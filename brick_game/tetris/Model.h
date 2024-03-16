#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include "../lib/defines.h"


namespace Tetris {

    class Model {
    public:
        Model();
        ~Model();

    private:
        GameInfo_t gameInfo_;
    };

} // namespace Tetris
#endif //SRC_MODEL_H
