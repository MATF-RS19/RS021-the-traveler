#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include <QDesktopWidget>
#include <QPalette>
#include <QPainter>
#include <QApplication>
#include <QMediaPlayer>
#include <QList>
#include <QDialog>
#include <QMessageBox>


#include "game.h"
//#include "city.h"
//#include "paris.h"

//QList<City*> listOfCities;

extern QMediaPlayer *music;

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

    setBackgroundImage(":/images/images/main.png");

    setWindowTitle("The Traveler");

    ui->play->setStyleSheet("border-image:url(:/buttons/buttons/play-button.png);");
    ui->play->setFixedSize(80,80);
    ui->play->setText("");
    // TODO alignment podesiti u kodu?!

    ui->controls->setStyleSheet("border-image:url(:/buttons/buttons/gamepad.png);");
    ui->controls->setFixedSize(80,80);
    ui->controls->setText("");
    // TODO alignment podesiti u kodu?!

    /*
     *
     * muzika TODO: napraviti poseban metod za to
     *
     */

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bckg_music.mp3"));
    music->play();


    /* TODO
     *
     * QPixmap pixmap("image_path");
     * QIcon ButtonIcon(pixmap);
     * sound->setIcon(ButtonIcon);
     * sound->setIconSize(pixmap.rect().size());
     *
     */
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

void MainMenuWindow::setBackgroundImage(QString imagePath)
{
    // ui->stackedWidget->setAutoFillBackground(true);

    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


void MainMenuWindow::on_play_clicked()
{
    if (ui->lineEditForName->text().isEmpty()) {
        QMessageBox msgBoxAlert;
        msgBoxAlert.setWindowTitle("Whoooa!");
        msgBoxAlert.setInformativeText("Enter your name!");
        QPushButton* myButton =new QPushButton("Ok");
        msgBoxAlert.addButton(myButton ,QMessageBox::AcceptRole);
        QObject::connect(myButton,&QPushButton::pressed,[](){qDebug("Ok is clicked!"); });
        int ret = msgBoxAlert.exec();
    }else {
        ui->stackedWidget->setCurrentIndex(3);
        Game *game = new Game();
        game->start();
        music->stop();
        close();

}
}
void MainMenuWindow::on_controls_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainMenuWindow::on_btnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainMenuWindow::on_actionSettings_triggered()
{
    //music->stop();
    SettingsDialog dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

void MainMenuWindow::on_actionQuit_triggered()
{
    close();
}

// TODO nadji dogadjaj on hover ili tako nesto!!!

// nije to

void MainMenuWindow::on_play_toggled(bool checked)
{/*
    ui->play->setStyleSheet("border-image:url(:/buttons/buttons/next.png);");
    ui->play->setFixedSize(80,80);
    ui->play->setText("");
    */
}

/*
 * // TODO TODO TODO TODO TODO
 *
#include <QCloseEvent>
#include <QMessageBox>
void MainWindow::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Exit?", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }

}*/
