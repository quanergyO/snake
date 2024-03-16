#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include "../../brick_game/snake/Model.h"

namespace Snake {


class Controller
{
public:
    Controller(Model &model);
    ~Controller() = default;

private:
    Model &model_;
};

} // namespace Snake

#endif //SRC_CONTROLLER_H
