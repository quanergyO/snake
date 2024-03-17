#include "mainwindow.h"

#include <QKeyEvent>

#include "ui_mainwindow.h"

MainWindow::MainWindow(Snake::Controller &controller, QWidget *parent)
    : QMainWindow(parent), controller_(controller), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateGameInfo(const GameInfo_t &gameInfo) {
  ui->levelNum->setText(QString::number(gameInfo.level));
  ui->scoreNum->setText(QString::number(gameInfo.score));
  ui->speedNum->setText(QString::number(gameInfo.speed));
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Left:
      sendUserAction(Left);
      break;
    case Qt::Key_Right:
      sendUserAction(Right);
      break;
    case Qt::Key_Up:
      sendUserAction(Up);
      break;
    case Qt::Key_Down:
      sendUserAction(Down);
      break;
    case Qt::Key_S:
      sendUserAction(Start);
      break;
    case Qt::Key_P:
      sendUserAction(Pause);
      break;
    case Qt::Key_Q:
      sendUserAction(Terminate);
      break;
    default:
      QMainWindow::keyPressEvent(event);
  }
}

void MainWindow::sendUserAction(UserAction_t action) {
  controller_.handleUserAction(action);
}