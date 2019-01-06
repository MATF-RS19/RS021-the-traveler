#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
//#include <QList>
//#include "city.h"
#include "settingsdialog.h"
#include "ui_settingsdialog.h"

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

    void on_btnBack_clicked();

    void on_actionSettings_triggered();
/*
public:
    QMediaPlayer *music;
*/

    void on_actionQuit_triggered();

    void on_play_toggled(bool checked);

private:
    Ui::MainMenuWindow *ui;
    void setWindowCenter(double widthCoef, double heightCoef);
    void setBackgroundImage(QString imagePath);
};

#endif // MAINMENUWINDOW_H
