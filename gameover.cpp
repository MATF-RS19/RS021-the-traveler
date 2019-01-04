#include "gameover.h"
//#include "ui_gameover.h"
#include "mainmenuwindow.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver),
{
    ui->setupUi(this);
    this->setFixedSize(410, 500);

    // set background
    QPixmap backgroundImg(":/images/map.jpg");
    backgroundImg = backgroundImg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImg);
    setPalette(palette);

    // add click actions to buttons
    connect(ui->exit, SIGNAL(clicked()), SLOT(exitOnClick()));
}

GameOver::~GameOver()
{
    delete ui;
}
/*
void GameOver::setText(QString msg, int value)
{
    score = value;
    setWindowTitle(msg);

    if (scores.back().second < value || scores.size() < 10) {
        ui->score->setText(msg + "\nYour score: " + QString::number(value) +
                                   "\nYou are in the top ten!");
        ui->subScore->setDisabled(false);
        ui->nameInput->setReadOnly(false);
    } else {
        ui->score->setText(msg + "\nYour score: " + QString::number(value));
    }

    displayScores();
}
*/
void GameOver::exitOnClick()
{
    QApplication::exit();
}
