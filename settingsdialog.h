#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QList>
#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QMediaPlayer>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    void showLabelChanges();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::SettingsDialog *ui;
    void setBackgroundImage(QString imagePath);
public:
    int pic_num = 0;
    QList<QPixmap*> pix;
    static QString first_player_img;
    QString second_player_img;
  //  QMediaPlayer * music_player = new QMediaPlayer();

};

#endif // SETTINGSDIALOG_H
