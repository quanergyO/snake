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

 protected:
  void keyPressEvent(QKeyEvent *event) override;

 private:
  void sendUserAction(UserAction_t action);

  Ui::MainWindow *ui;
  Snake::Controller &controller_;
};

#endif  // MAINWINDOW_H