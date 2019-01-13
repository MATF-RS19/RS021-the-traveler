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

    pix.append(new QPixmap(":/images/images/tokyo_img.png"));
    pix.append(new QPixmap(":/images/images/paris_img.png"));
    pix.append(new QPixmap(":/images/images/left2.png"));

showLabelChanges();

//ui->radioButton->setIcon();
ui->radioButton->setText("off");
ui->radioButton->setStyleSheet("background-color: #C2D7F1");
ui->radioButton_2->setText("on");
ui->radioButton_2 ->setStyleSheet("background-color: #C2D7F1");

ui->pushButton->setStyleSheet("border-image:url(:/buttons/buttons/next.png);");
ui->pushButton->setFixedSize(30,30);
ui->pushButton->setText("");
ui->pushButton_2->setStyleSheet("border-image:url(:/buttons/buttons/back.png);");
ui->pushButton_2->setFixedSize(30,30);
ui->pushButton_2->setText("");


}

void SettingsDialog::showLabelChanges() {

    if (pic_num == 0) {
        // dimenzije labele
        int w = ui->label->width();
        int h = ui->label->height();
        // skaliram pixmap na w x h dim.
        ui->label->setPixmap(pix[0]->scaled(w,h,Qt::KeepAspectRatio));
    }
    else if (pic_num == 1) {
        // dimenzije labele
        int w = ui->label->width();
        int h = ui->label->height();
        // skaliram pixmap na w x h dim.
        ui->label->setPixmap(pix[1]->scaled(w,h,Qt::KeepAspectRatio));

    }
    else if (pic_num == 2) {
        // dimenzije labele
        int w = ui->label->width();
        int h = ui->label->height();
        // skaliram pixmap na w x h dim.
        ui->label->setPixmap(pix[2]->scaled(w,h,Qt::KeepAspectRatio));
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pushButton_clicked()
{
    pic_num++;
    showLabelChanges();
    if (pic_num >= 2) {
        pic_num = 2;
    }

}

void SettingsDialog::on_pushButton_2_clicked()
{

    pic_num--;
    showLabelChanges();
    if (pic_num <= 0) {
        pic_num = 0;
    }
}

void SettingsDialog::on_radioButton_clicked()
{
    music->stop();

}

void SettingsDialog::on_radioButton_2_clicked()
{
    music->play();
}

void SettingsDialog::setBackgroundImage(QString imagePath)
{
    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
