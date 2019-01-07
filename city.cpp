#include "city.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QSize>

#include <QJsonArray>
#include <QJsonObject>

City::City(QString name, int playerPosX, int playerPosY){
    _name = name;
    _scene = new QGraphicsScene();
    setScene(_scene);
    _finished = false;
    _player = new Player(playerPosX, playerPosY);
    _scene->addItem(_player);
    _scene->addItem(_player->getFakePlayer());
}

City::~City(){
    if(_finished){
        this->close();
    }
}

    /*
     * izmenjen metod za postavljanje pozadine
     * jer prethodni nije imao mogucnost skaliranja slike
     * (prethodni kod je zakomentarisan)
     */

void City::setBackgraundImage(QString path){
   // setBackgroundBrush(QBrush(QImage(path)));

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
/*
bool City::ifFinished()
{
    return _finished;
}*/

void City::buildBasic(const QJsonObject &jsonObj, const QString &img, const QJsonArray &buildings){

    setCityDimensions(jsonObj["x"].toInt(), jsonObj["y"].toInt(), jsonObj["w"].toInt(), jsonObj["h"].toInt());
    setBackgraundImage(img);

    foreach(const QJsonValue &building, buildings) {
        _scene->addItem(new Building(building["x"].toInt(), building["y"].toInt(),building["w"].toInt(),building["h"].toInt(), building["src"].toString(), building["type"].toInt()));
    }
}

void City::moveToNextLevel(){
    if(_finished){
        this->close();
    }
}
