#include "tokyo.h"
#include <QDebug>
#include "player.h"
#include <QTimer>
#include <QObject>

void Tokyo::buildSpecial(QJsonObject &json){

    /*
     * Postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    listOfSushi.append(new Sushi(730, 5));
    listOfSushi.append(new Sushi(830, 190));
    listOfSushi.append(new Sushi(750, 350));
    listOfSushi.append(new Sushi(750, 470));
    _scene->addItem(listOfSushi[0]);
    _scene->addItem(listOfSushi[1]);
    _scene->addItem(listOfSushi[2]);
    _scene->addItem(listOfSushi[3]);

    connect(_player, SIGNAL(takeFood(QGraphicsItem *)), this, SLOT(removeFood(QGraphicsItem *)));
    connect(this, SIGNAL(freeNextLevel()), _player, SLOT(toTheExit()) );
    connect(_player, SIGNAL(escapedEvilObjects()), this, SLOT(finished()));

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(50);
}

void Tokyo::removeFood(QGraphicsItem *item) {
    _scene->removeItem(item);
    numOfSushi--;

    if(numOfSushi == 0) {
        emit freeNextLevel();
    }
}
