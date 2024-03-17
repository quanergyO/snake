#include "Controller.h"

namespace s21 {
namespace Snake
{

Controller::Controller(Model &model)
    : model_(model)
{}

void Controller::move(const UserAction_t &action)
{
    model_.move(action);
}

} // namespace Snake
} // namespace s21
