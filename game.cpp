#include "game.h"
#include "paris.h"
#include "tokyo.h"
#include <QDebug>
#include <iterator>
#include "player.h"
#include "myqfile.h"

#include <QMediaPlayer>
#include <QJsonArray>
#include <QApplication>
#include <QGraphicsItem>

extern int a;
extern int change_now;
// 0 na poc
Game::Game(){
    _music = new QMediaPlayer();
    paris = new Paris();
    tokyo = new Tokyo();
    listOfCities.push_back(tokyo);
    listOfCities.push_back(paris);
}

void Game::start(){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */

   // qDebug() << a;
   // qDebug() << listOfCities[0]->_player->lifes;

    //QList<City*>::iterator it;
    //for(it = listOfCities.begin(); it != listOfCities.end(); it++)
        QString fileName = ":/json/" + tokyo->getName() + ".json";
        qDebug() << fileName;
        myQfile f(fileName);
        QJsonDocument cityD = f.makeJSONDoc();

        QJsonArray buildings = cityD["buildings"].toArray();
       // if (change_now == 1)
        tokyo->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

        QJsonObject obj = cityD["special"].toObject();
        tokyo->buildSpecial(obj);

        QString musicUrl = cityD["music"].toString();
        qDebug() << musicUrl;
      //  _music->setMedia(QUrl(musicUrl));
      //  _music->play();

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




    /*
    listOfCities[0]->show();
    qDebug() << listOfCities[0]->_player->lifes;
qDebug() << a;
    if (listOfCities[0]->_player->lifes <= 0) {
         // listOfCities[0]->invalidateScene();
         // listOfCities[1]->show();
         qDebug() << "sdssa";
         listOfCities[1]->show();
    }
    */

    listOfCities[0]->show();
    connect(listOfCities[0]->_player, SIGNAL(escapedEvilObjects(int)), this, SLOT(goToNextLevel(int)));
}

void Game::loadNextLevel()
{

    /*QList<City*>::iterator it;
    for(it = listOfCities.begin(); it != listOfCities.end(); it++)*/
        QString fileName = ":/json/" + paris->getName() + ".json";
        qDebug() << fileName;
        myQfile f(fileName);
        QJsonDocument cityD = f.makeJSONDoc();

        QJsonArray buildings = cityD["buildings"].toArray();
       // if (change_now == 1)
        paris->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

        QJsonObject obj = cityD["special"].toObject();
        paris->buildSpecial(obj);

        QString musicUrl = cityD["music"].toString();
        qDebug() << musicUrl;
       // _music->setMedia(QUrl(musicUrl));
       // _music->play();
}

void Game::goToNextLevel(int level){
    //qDebug() << "goToNextLevel";
    for(QGraphicsItem *item: listOfCities[level-1]->items()) {
    //listOfCities[level-1]->getScene()->clear();
        delete item;
        _music->stop();
        listOfCities[level-1]->close();
    }
    //listOfCities[level-1]->close();
    loadNextLevel();

    listOfCities[level]->show();
}



