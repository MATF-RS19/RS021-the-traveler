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
#include <QSize>
#include <QImage>
#include <QGraphicsItem>

extern int a;
extern int change_now;
// 0 na poc
Game::Game(QGraphicsView * view)
    : _view(view) {

    _level = 0;

    _music = new QMediaPlayer();

    paris = new Paris();
    tokyo = new Tokyo();
    _listOfCities.push_back(tokyo);
    _listOfCities.push_back(paris);

    _player = new Player();
}

Game::~Game()
{

}

void Game::start(int level){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */

    QString fileName = ":/json/" + _listOfCities[level]->getName() + ".json";
    qDebug() << fileName;
    myQfile f(fileName);
    QJsonDocument cityD = f.makeJSONDoc();

    QString musicUrl = cityD["music"].toString();
    _music->setMedia(QUrl(musicUrl));
    _music->play();

    setBackground(cityD["background"].toString());
    QJsonArray buildings = cityD["buildings"].toArray();
    QJsonObject obj = cityD["special"].toObject();
    _listOfCities[level]->buildSpecial(obj);

    qDebug() << "pred plejera";
    _player->setPosition(250, 230);
    _player->setStep(20);
    addItem(_player);

    qDebug() << "pred zgrade";
    _listOfCities[level]->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings, _player);

    for(Building * b: _listOfCities[level]->getListOfBuildings())
        addItem(b);

    _listOfCities[level]->buildSpecial(obj);
   /* for(Building * b: buildingg)
        addItem(b);*/
   // qDebug() << a;
   // qDebug() << listOfCities[0]->_player->lifes;

    //QList<City*>::iterator it;
    //for(it = listOfCities.begin(); it != listOfCities.end(); it++)

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

    //_listOfCities[0]->show();

    connect(_player, SIGNAL(escapedEvilObjects(int)), this, SLOT(goToNextLevel(int)));
}

int Game::getLevel() const
{
    return _level;
}
/*
void Game::loadNextLevel()
{*/

    /*QList<City*>::iterator it;
    for(it = listOfCities.begin(); it != listOfCities.end(); it++)*/
       /* QString fileName = ":/json/" + paris->getName() + ".json";
        qDebug() << fileName;
        myQfile f(fileName);
        QJsonDocument cityD = f.makeJSONDoc();

        QJsonArray buildings = cityD["buildings"].toArray();
       // if (change_now == 1)
        //paris->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

        QJsonObject obj = cityD["special"].toObject();
        paris->buildSpecial(obj);

        QString musicUrl = cityD["music"].toString();
        qDebug() << musicUrl;
        _music->setMedia(QUrl(musicUrl));
        _music->play();
}*/

void Game::goToNextLevel(int level){
    level = 1;
    //qDebug() << "goToNextLevel";
    for(QGraphicsItem *item: this->items()) {
        if(item != _player) {
    //listOfCities[level-1]->getScene()->clear();
            delete item;
            _music->stop();
        }
        //_listOfCities[level-1]->close();
    }
    //listOfCities[level-1]->close();
    start(1);


}

void Game::setBackground(const QString img)
{
    QImage * image = new QImage(img);
    QBrush * brush = new QBrush(image->scaled(_view->size(),Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    setBackgroundBrush(*brush);
}



