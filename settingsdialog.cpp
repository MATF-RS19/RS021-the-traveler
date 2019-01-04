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

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/main.png");
    ui->label->setPixmap(pix);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
