#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainMenuWindow *ui;
    void setWindowCenter(double widthCoef, double heightCoef);
    void setBackgroundImage();
};

#endif // MAINMENUWINDOW_H
