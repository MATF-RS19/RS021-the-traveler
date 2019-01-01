#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
//#include <QList>
//#include "city.h"

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
    ~MainMenuWindow();

private slots:
    void on_play_clicked();

    void on_controls_clicked();

    void on_howToPlay_clicked();

    void on_quit_clicked();

    void on_btnBack_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainMenuWindow *ui;
    QMediaPlayer *music;
    void setWindowCenter(double widthCoef, double heightCoef);
    void setBackgroundImage(QString imagePath);
};

#endif // MAINMENUWINDOW_H
