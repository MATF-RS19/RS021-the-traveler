#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDesktopWidget>
#include <QPalette>
#include <QPainter>
#include <QApplication>
#include <QMediaPlayer>
#include <QList>
#include <QDialog>
#include <QPixmap>
#include <QDebug>
#include <QList>

#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

extern QMediaPlayer *music;

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    setWindowTitle("Settings");
    setBackgroundImage(":/images/images/dialog_bckg.jpg");

    //QPixmap pix(":/images/images/main.png");
    //ui->label->setPixmap(pix);

    pix.append(new QPixmap(":/images/images/main.png"));
    pix.append(new QPixmap(":/images/images/fire.png"));
    pix.append(new QPixmap(":/images/images/left2.png"));

showLabelChanges();

//ui->radioButton->setIcon();
ui->radioButton->setText("off");
ui->radioButton->setStyleSheet("background-color: #C2D7F1");
ui->radioButton_2->setText("on");
ui->radioButton_2 ->setStyleSheet("background-color: #C2D7F1");

ui->pushButton->setStyleSheet("border-image:url(:/buttons/buttons/back.png);");
ui->pushButton->setFixedSize(30,30);
ui->pushButton->setText("");
ui->pushButton_2->setStyleSheet("border-image:url(:/buttons/buttons/next.png);");
ui->pushButton_2->setFixedSize(30,30);
ui->pushButton_2->setText("");


}

void SettingsDialog::showLabelChanges() {

    if (pic_num == 0) {
        ui->label->setPixmap(*pix[0]);
    }
    else if (pic_num == 1) {
        ui->label->setPixmap(*pix[1]);
    }
    else if (pic_num == 2) {
        ui->label->setPixmap(*pix[2]);
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pushButton_clicked()
{
        pic_num++;
      //  ui->label->show();
        qDebug() << pic_num;
        showLabelChanges();
        if (pic_num >= 2) {
            pic_num = 2;
        }

}

void SettingsDialog::on_pushButton_2_clicked()
{
    pic_num--;
  //  ui->label->show();
    qDebug() << pic_num;
    showLabelChanges();
    if (pic_num <= 0) {
        pic_num = 0;
    }
}

void SettingsDialog::on_radioButton_clicked()
{
    //first_player_img = ":/images/images/left2.png";
    music->stop();

}

void SettingsDialog::on_radioButton_2_clicked()
{
   // music->setMedia(QUrl("qrc:/sounds/bckg_music.mp3"));
    music->play();
}

void SettingsDialog::setBackgroundImage(QString imagePath)
{
    // ui->stackedWidget->setAutoFillBackground(true);

    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
