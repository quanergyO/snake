#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

#include "../../../controllers/snake/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(Snake::Controller &controller, QWidget *parent = nullptr);
  ~MainWindow();

  void updateGameInfo(const GameInfo_t &gameInfo);
  void handleMouseClick(QMouseEvent *event);

 protected:
  void keyPressEvent(QKeyEvent *event) override;

 private:
  void sendUserAction(UserAction_t action);

  Ui::MainWindow *ui;
  s21::Snake::Controller &controller_;
  const size_t ROWS = 20;
  const size_t COLS = 10;
};

#endif  // MAINWINDOW_H