#include "howtoplaydialog.h"
#include "ui_howtoplaydialog.h"

HowToPlayDialog::HowToPlayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowToPlayDialog)
{
    ui->setupUi(this);
}

HowToPlayDialog::~HowToPlayDialog()
{
    delete ui;
}
