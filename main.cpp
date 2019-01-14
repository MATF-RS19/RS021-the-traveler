#include "mainmenuwindow.h"
#include <QApplication>
#include "sushi.h"
#include <QMediaPlayer>

QMediaPlayer *music;
QString nameText;

int main(int argc, char *argv[])
{
    /*
     * Inicijalizacija globalnih promenljivih.
     */

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bckg_music.mp3"));
    QString nameText = "";

    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();

    return a.exec();
}
