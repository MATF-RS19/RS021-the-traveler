#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/joki/firstApp/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);  // skalira se na dim. prozora
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
