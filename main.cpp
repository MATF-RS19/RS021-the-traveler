#include "mainmenuwindow.h"
#include <QApplication>
#include "evil.h"
#include <QMediaPlayer>

int a;
QMediaPlayer *music;

int main(int argc, char *argv[])
{
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bckg_music.mp3"));
    a = 0;
    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();

    return a.exec();
}
