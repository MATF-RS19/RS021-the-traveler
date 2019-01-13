#include "city.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QSize>

#include <QJsonArray>
#include <QJsonObject>

City::City(QString name, int playerPosX, int playerPosY, int playerStep, int level_number)
    :_name (name), _level_number(level_number) {
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


void City::setCityDimensions(int x, int y, int w, int h){
    /*
     * Postavljaju se dimenzije i pozicija grada, tj. scene u kojoj ce biti prikazan grad.
     * I dimenzije pogleda se postavljaju na iste vrednosti, kako bismo imali pogled na celu scenu.
     */
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

    foreach(const QJsonValue &building, buildings) {
        _scene->addItem(new Building(building["x"].toInt(), building["y"].toInt(),building["w"].toInt(),building["h"].toInt(), building["src"].toString(), building["type"].toInt()));
    }
}

/*
 * prelazak na sledeci nivo
 */

void City::finished() {
    emit goToNextLevel(this->getLevel());
}
