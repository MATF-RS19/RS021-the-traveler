#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include <QDesktopWidget>
#include <QPalette>

MainMenuWindow::MainMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);

    /*
     *
     * za koliko korigujemo velicinu prozora
     * u odnosu na velicinu ekrana
     *
     */

    setWindowCenter(2,1.7);
    setFixedSize(size());

    /*
     *
     * prva strana ima indeks 0
     * inicijalno je -1
     *
     */

    ui->stackedWidget->setCurrentIndex(0);

    setBackgroundImage();

    setWindowTitle("The Traveler");
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}

/*
*
* Ovaj metod podesava velicinu prozora aplikacije,
* tako sto velicinu desktopa deli zadatim faktorima
*
*/

void MainMenuWindow::setWindowCenter(double widthCoef, double heightCoef)
{
    /*
     *
     * QApplication::desktop() funkcija vraca instancu QDesktopWidget
     * QDesktopWidget klasa pruza informacije o desktopu korisnika
     * jedna takva informacija je velicina desktopa koju ovde koristimo
     *
    */

    int windowWidth  = QApplication::desktop()->width();
    int windowHeight = QApplication::desktop()->height();

    double width  = windowWidth / widthCoef;
    double height = windowHeight / heightCoef;

    int x = (windowWidth - int(width)) / 2;
    int y = (windowHeight - int(height)) / 2;

    /*
     *
     * ako se prozoru menja velicina nakon
     * sto je podesen setFixedSize()
     *
     */

    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    setMinimumSize(0, 0);

    ui->stackedWidget->resize(int(width), int(height));
    resize(int(width), int(height));
    setFixedSize(size());

    /*
     *
     * move pomera prozor (na sredinu ekrana)
     *
     */

    move(x, y);
}

    /*
     *
     * Ovaj metod postavlja pozadinu forme
     *
     */

void MainMenuWindow::setBackgroundImage()
{
    // ui->stackedWidget->setAutoFillBackground(true);

    QPixmap bkgnd("/home/joki/TheTraveler/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


void MainMenuWindow::on_play_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);  // TODO dodati 1. nivo (i ostale)
}

void MainMenuWindow::on_controls_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainMenuWindow::on_howToPlay_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainMenuWindow::on_quit_clicked()
{
    close();
}
