#include "game.h"
#include "paris.h"
#include "tokyo.h"
#include <QDebug>
#include <iterator>
#include "player.h"
#include "myqfile.h"
#include "london.h"

#include <QMediaPlayer>
#include <QJsonArray>
#include <QApplication>
#include <QGraphicsItem>

extern int change_now;
Game::Game(){
    _music = new QMediaPlayer();

    _playlist->addMedia(QUrl("qrc:/sounds/bckg_music.mp3"));
    _playlist->addMedia(QUrl("qrc:/sounds/song_01.mp3"));
    _playlist->addMedia(QUrl("qrc:/sounds/song_02.mp3"));
    _playlist->addMedia(QUrl("qrc:/sounds/song_03.mp3"));
    _playlist->addMedia(QUrl("qrc:/sounds/song_04.mp3"));
    _playlist->addMedia(QUrl("qrc:/sounds/song_05.mp3"));
    _playlist->shuffle();
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);

    _music->setPlaylist(_playlist);
    _music->play();

    Paris *paris = new Paris();
    Tokyo *tokyo = new Tokyo();
    London * london = new London();
    listOfCities.push_back(tokyo);
    listOfCities.push_back(london);
    listOfCities.push_back(paris);
}

void Game::start(int level){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */

    QString fileName = ":/json/" + listOfCities[level]->getName() + ".json";
    qDebug() << fileName;
    myQfile f(fileName);
    QJsonDocument cityD = f.makeJSONDoc();

    QJsonArray buildings = cityD["buildings"].toArray();
    listOfCities[level]->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

    QJsonObject obj = cityD["special"].toObject();
    listOfCities[level]->buildSpecial(obj);


    listOfCities[level]->show();
    connect(listOfCities[level], SIGNAL(goToNextLevel(int)), this, SLOT(goToNextLevel(int)));
}

void Game::goToNextLevel(int level){
    listOfCities[level]->close();

    level += 1;
    start(level);
    listOfCities[level]->show();
}



