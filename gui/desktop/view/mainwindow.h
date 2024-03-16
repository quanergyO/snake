#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../../../controllers/snake/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Snake::Controller &controller, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Snake::Controller &controller_;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
