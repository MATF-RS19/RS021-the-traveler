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

    Paris * paris = new Paris();
    Tokyo * tokyo = new Tokyo();
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
    myQfile f(fileName);
    QJsonDocument cityD = f.makeJSONDoc();

    QString musicUrl = cityD["music"].toString();
    _music->setMedia(QUrl(musicUrl));
    _music->play();

    setBackground(cityD["background"].toString());
    QJsonArray buildings = cityD["buildings"].toArray();
    QJsonObject obj = cityD["special"].toObject();
    _listOfCities[level]->buildSpecial(obj);

    _player->setPosition(250, 230);
    _player->setStep(20);
    addItem(_player);

    _listOfCities[level]->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings, _player);

    for(Building * b: _listOfCities[level]->getListOfBuildings())
        addItem(b);

    _listOfCities[level]->buildSpecial(obj);

   // qDebug() << a;
   // qDebug() << listOfCities[0]->_player->lifes;

    connect(_player, SIGNAL(escapedEvilObjects(int)), this, SLOT(goToNextLevel(int)));
}

void Game::goToNextLevel(int level){
    /*
    *
    * Ukloniti komentar
    * Ako zelite da zavrsite igru
    * Nakon prvog nivoa
    *
    *
    * if(level == 1)
    * emit finishedGame();
    *
    */
    qDebug() << "krajj";
    level = 1;
    for(QGraphicsItem *item: this->items()) {
    if(item != _player) {
        delete item;
        _music->stop();
        }
    }

    start(level);
}

void Game::setBackground(const QString img)
{
    QImage * image = new QImage(img);
    QBrush * brush = new QBrush(image->scaled(_view->size(),Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    setBackgroundBrush(*brush);
}



