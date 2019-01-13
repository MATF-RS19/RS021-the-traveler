#include "howtoplaydialog.h"
#include "ui_howtoplaydialog.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QTextBrowser>
#include <QDebug>

HowToPlayDialog::HowToPlayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowToPlayDialog)
{
    ui->setupUi(this);
    this->setFixedSize(600, 400);

    setWindowTitle("Settings");
    setBackgroundImage(":/images/images/dialog_bckg.jpg");

    QString text;
    // QTextBrowser *textBrowser = new QTextBrowser();
    int number_of_lines = 0;

    QFile inputFile(":/text/text/AboutGame.txt");

    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       while (!in.atEnd()){
          QString line = in.readLine();
          text.append(line);
          text.append("\n");
          number_of_lines ++;
       }
       ui->textBrowser->setText(text);

       /*
        * Prilagodjavamo velicinu textBrowsera njegovom sadrzaju
        */

       QFontMetrics font_metrics(ui->textBrowser->font());
       int font_height = font_metrics.height();
       int height = font_height * number_of_lines;

        ui->textBrowser->setMinimumHeight(height);
        ui->textBrowser->setMaximumHeight(height);

        inputFile.close();
}
    else qDebug() << "Neuspelo otvaranje datoteke";
}

HowToPlayDialog::~HowToPlayDialog()
{
    delete ui;
}

void HowToPlayDialog::setBackgroundImage(QString imagePath)
{
    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
