#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Snake::Controller &controller, QWidget *parent)
    : QMainWindow(parent)
    , controller_(controller)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

