#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include "paris.h"
#include "paris_utility.h"

#include <QJsonObject>
#include <QJsonArray>

extern FinalTest *testParis;

void Paris::buildSpecial(QJsonObject &json) {/*

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QJsonArray streets = json["streets"].toArray();
        //QJsonArray streets = json.value("streets").toArray();
        foreach(const QJsonValue &street, streets) {
            makeStreet(street["src"].toString(), street["sx"].toInt(), street["sy"].toInt(),
                                                 street["px"].toInt(), street["py"].toInt());
        }*/

        /* Postavljaju se zgrade */
       /* QJsonObject eiffelObj =  json["eiffel"].toObject();
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
        _scene->addItem(triumphalArch);

        QJsonObject keyObj = json["key"].toObject();
        _key = new Building(keyObj["x"].toInt(), keyObj["y"].toInt(),
                            keyObj["w"].toInt(), keyObj["h"].toInt(),
                            keyObj["src"].toString(), keyObj["type"].toInt());
        _key->setName("key_paris");
        _scene->addItem(_key);


        connect(testParis, SIGNAL(notifyParis()), this, SLOT(isFinished()));
*/
}

void Paris::isFinished(){
    //this->close();
    qDebug() << "PARIS - isFinished";
}


/*void Paris::buildCity(){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCityDimensions(0, 0, 900, 599);
    setBackgraundImage(":/images/images/paris_background6.jpg");*/

    /* Postavlja se ulica */
   /* makeStreet(":/images/images/paris_street_3.png", 400, 100, 0, 200);
    makeStreet(":/images/images/paris_street_4.png", 100, 100, 400, 200);
    makeStreet(":/images/images/paris_street_5.png", 100, 100, 400, 300);
    makeStreet(":/images/images/paris_street_3.png", 400, 100, 500, 300);
    makeStreet(":/images/images/paris_street_1.png", 100, 221, 250, 0);*/

    /* Postavljaju se zgrade */
   /* Building *eiffel = new Building(5,150, 250,300,":/images/images/paris_eiffel_tower.png");
    Building *notreDame = new Building(350,8, 150,200,":/images/images/paris_notre_dame2.jpg");
    Building *triumphalArch = new Building(10,8, 180,180,":/images/images/paris-triumphal-arch.svg");
    _key = new Building(110,80, 10,20,":/images/images/paris_key.png");
    _key->setName("key_paris");

    listOfBuildings.append(eiffel);
    listOfBuildings.append(triumphalArch);
    listOfBuildings.append(_key);
    listOfBuildings.append(notreDame);

    listOfBuildings.append(new Building(320,55, 100,120, ":/images/images/paris_tree3.png"));
    listOfBuildings.append(new Building(300,230, 200,120, ":/images/images/paris_park.png"));
    listOfBuildings.append(new Building(240,180, 70,90, ":/images/images/paris_tree1.png"));
    listOfBuildings.append(new Building(280,180, 70,90, ":/images/images/paris_tree1.png"));
    listOfBuildings.append(new Building(320,180, 70,90, ":/images/images/paris_tree1.png"));
    listOfBuildings.append(new Building(360,180, 70,90, ":/images/images/paris_tree1.png"));
    listOfBuildings.append(new Building(400,180, 70,90, ":/images/images/paris_tree1.png"));

    qDebug() << "***************";
    foreach(Building *b, listOfBuildings) _scene->addItem(b);

    //QObject::connect((QObject*)_player, SIGNAL(keyReleaseEvent), (QObject*)_key, SLOT(findKey()));

    //QObject::connect(_player,SIGNAL(_player->keyReleaseEvent()), _key, SLOT(findKey()));*/
/*
    qDebug() << "player x: " << _player->getX();
    qDebug() << "player y: " << _player->getY();

    qDebug() << "_foundKey: " << _foundKey;
    if(qAbs(_player->getX() - key->x()) <= 120 || qAbs(_player->getY() - key->y()) <= 10){
        _foundKey = true;
        qDebug() << "_foundKey: " << _foundKey;
    }*/

//}

void Paris::makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos){
    QGraphicsPixmapItem *street = new QGraphicsPixmapItem();
    QPixmap *streetImage = new QPixmap(imgPath);
    *streetImage = streetImage->scaled(xScale, yScale);
    street->setPixmap(*streetImage);
    street->setPos(xPos, yPos);
    street->setZValue(-1);
    _scene->addItem(street);
}
/*
void Paris::findKey(){

    qDebug() << "player x: " << _player->getX();
    qDebug() << "player y: " << _player->getY();

    qDebug() << "_foundKey: " << _foundKey;
    if(qAbs(_player->getX() - _key->x()) <= 120){
        _foundKey = true;
        qDebug() << "_foundKey: " << _foundKey;
    }

}
*/
