#include "mainwindow.h"

#include <QKeyEvent>

#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Snake::Controller &controller, QWidget *parent)
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
  double cellWidth = static_cast<double>(ui->widget->width()) / COLS;
  double cellHeight = static_cast<double>(ui->widget->height()) / ROWS;
  Point_t snakeHead = controller_.getSnakeHead();
  size_t newX = snakeHead.x;
  size_t newY = snakeHead.y;
  switch (event->key()) {
    case Qt::Key_Left:
      newX = (snakeHead.x - 1 + COLS) % COLS;
      break;
    case Qt::Key_Right:
      newX = (snakeHead.x + 1) % COLS;
      break;
    case Qt::Key_Up:
      newY = (snakeHead.y - 1 + ROWS) % ROWS;
      break;
    case Qt::Key_Down:
      newY = (snakeHead.y + 1) % ROWS;
      break;
    default:
      QMainWindow::keyPressEvent(event);
      return;
  }
  controller_.moveSnakeTo(newX, newY);
  ui->widget->update();
}

void MainWindow::sendUserAction(UserAction_t action) {
  if (state = GAME_OVER) {
    break;
  } else
    sigact(action);
}
