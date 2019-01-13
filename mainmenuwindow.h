#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "settingsdialog.h"
#include "ui_settingsdialog.h"

extern QString nameText;


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

    void on_actionQuit_triggered();

    void on_play_toggled(bool checked);

    void on_actionHow_to_play_triggered();

private:
    Ui::MainMenuWindow *ui;
    void setWindowCenter(double widthCoef, double heightCoef);
    void setBackgroundImage(QString imagePath);
};

#endif // MAINMENUWINDOW_H
