#include "city.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QSize>

#include <QJsonArray>
#include <QJsonObject>

City::City(QString name, int playerPosX, int playerPosY, int playerStep, int level_number)
    :_level_number(level_number), _name(name) {
    _scene = new QGraphicsScene();
    setScene(_scene);

    _player = new Player(playerPosX, playerPosY, playerStep);
    _scene->addItem(_player);
    _scene->addItem(_player->getFakePlayer());
}

QGraphicsScene * City::getScene()
{
    return _scene;
}

City::~City(){

}

void City::setBackgraundImage(QString path){
    QImage *image = new QImage(path);
    QBrush *brush = new QBrush(image->scaled(this->size(),Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    setBackgroundBrush(*brush);
}

/*
 * Postavljaju se dimenzije i pozicija grada,
 * tj. scene u kojoj ce biti prikazan grad.
 *
 * Dimenzije pogleda se postavljaju na iste vrednosti,
 * kako bismo imali pogled na celu scenu.
 */

void City::setCityDimensions(int x, int y, int w, int h){
    _scene->setSceneRect(x, y, w, h);
    setFixedSize(w, h);
}

QString City::getName() {
    return _name;
}

int City::getLevel()
{
    return _level_number;
}

void City::buildBasic(const QJsonObject &jsonObj, const QString &img, const QJsonArray &buildings){

    setCityDimensions(jsonObj["x"].toInt(), jsonObj["y"].toInt(), jsonObj["w"].toInt(), jsonObj["h"].toInt());
    setBackgraundImage(img);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    foreach(const QJsonValue &building, buildings) {
        _scene->addItem(new Building(building["x"].toInt(), building["y"].toInt(),building["w"].toInt(),building["h"].toInt(), building["src"].toString(), building["type"].toInt()));
    }
}

/*
 * Prelazak na sledeci nivo.
 */

void City::finished() {
    emit goToNextLevel(this->getLevel());
}

void City::removeTee(QGraphicsItem *item) {
    _scene->removeItem(item);
    numOfTees--;

    if(numOfTees == 0) {
        emit goToNextLevel(_level_number);
    }
}

void City::removeSushi(QGraphicsItem *item) {
    _scene->removeItem(item);
    numOfSushi--;

    if(numOfSushi == 0) {
        emit goToNextLevel(_level_number);
    }
}

