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

extern int a;
extern int change_now;
// 0 na poc
Game::Game(){

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
    QMediaPlayer * music = new QMediaPlayer();

    QList<City*>::iterator it;
    for(it = listOfCities.begin(); it != listOfCities.end(); it++){
        QString fileName = ":/json/" + (*it)->getName() + ".json";
        qDebug() << fileName;
        myQfile f(fileName);
        QJsonDocument cityD = f.makeJSONDoc();

        QJsonArray buildings = cityD["buildings"].toArray();
       // if (change_now == 1)
        (*it)->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

        QJsonObject obj = cityD["special"].toObject();
        (*it)->buildSpecial(obj);

        QString musicUrl = cityD["music"].toString();
        qDebug() << musicUrl;
        music->setMedia(QUrl(musicUrl));
        music->play();

    }


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

void Game::goToNextLevel(int level){
    //qDebug() << "goToNextLevel";
    listOfCities[level-1]->close();
    listOfCities[level]->show();
}



