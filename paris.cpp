#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include "paris.h"
#include "paris_utility.h"
#include <QJsonObject>
#include <QJsonArray>

extern FinalTest *testParis;

void Paris::buildSpecial(QJsonObject &json) {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QJsonArray streets = json["streets"].toArray();
        //QJsonArray streets = json.value("streets").toArray();
        foreach(const QJsonValue &street, streets) {
            makeStreet(street["src"].toString(), street["sx"].toInt(), street["sy"].toInt(),
                                                 street["px"].toInt(), street["py"].toInt());
        }

        /* Postavljaju se zgrade */
        QJsonObject eiffelObj =  json["eiffel"].toObject();
        Building *eiffel = new Building(eiffelObj["x"].toInt(), eiffelObj["y"].toInt(),
                                        eiffelObj["w"].toInt(), eiffelObj["h"].toInt(),
                                        eiffelObj["src"].toString(), eiffelObj["type"].toInt());
        eiffel->setName("Eiffel");
        _scene->addItem(eiffel);

        QJsonObject notreDameObj =  json["notreDame"].toObject();
        Building *notreDame = new Building(notreDameObj["x"].toInt(), notreDameObj["y"].toInt(),
                                           notreDameObj["w"].toInt(), notreDameObj["h"].toInt(),
                                           notreDameObj["src"].toString(), notreDameObj["type"].toInt());
        notreDame->setName("Notre Dame");
        _scene->addItem(notreDame);

        QJsonObject triumphalArchObj =  json["triumphalArch"].toObject();
        Building *triumphalArch = new Building(triumphalArchObj["x"].toInt(), triumphalArchObj["y"].toInt(),
                                               triumphalArchObj["w"].toInt(), triumphalArchObj["h"].toInt(),
                                               triumphalArchObj["src"].toString(), triumphalArchObj["type"].toInt());
        triumphalArch->setName("Triumphal arch");
        _scene->addItem(triumphalArch);

}

void Paris::makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos){
    QGraphicsPixmapItem *street = new QGraphicsPixmapItem();
    QPixmap *streetImage = new QPixmap(imgPath);
    *streetImage = streetImage->scaled(xScale, yScale);
    street->setPixmap(*streetImage);
    street->setPos(xPos, yPos);
    street->setZValue(-1);
    _scene->addItem(street);
}

void Paris::removeSushi(QGraphicsItem *item) {

}
