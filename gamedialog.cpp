#include "gamedialog.h"
#include "ui_gamedialog.h"
#include "game.h"

#include <QDesktopWidget>

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);

    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Game * game = new Game(ui->view);
    ui->view->setScene(game);
    game->setSceneRect(0, 0, 900, 599);
    ui->view->setFixedSize(900, 599);
    ui->view->show();
    ui->view->setFocus();
    game->start(0);
}

GameDialog::~GameDialog()
{
    delete ui;
}
