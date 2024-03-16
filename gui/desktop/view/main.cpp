#include "mainwindow.h"

#include <QApplication>
#include "../../../brick_game/snake/Model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Snake::Model model;
    Snake::Controller controller(model);
    MainWindow w(controller);
    w.show();
    return a.exec();
}
