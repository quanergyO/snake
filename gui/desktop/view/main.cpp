#include <QApplication>

#include "../../../brick_game/snake/Model.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Snake::Model model;
  s21::Snake::Controller controller(model);
  MainWindow w(controller);
  w.show();
  return a.exec();
}
