#include "tokyo.h"
#include "globalvars.h"
#include <QDebug>
#include "bullet.h"
#include "player.h"
#include <QTimer>
#include <QObject>

void Tokyo::buildSpecial(QJsonObject &json){

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    //*******************************************************************************
    // TODO
    // PROBLEM:
    // svi objekti (buildings) su u listi listOfBuildings ali se NE PRIKAZUJU na sceni!

    //foreach(Building *b, listOfBuildings) _scene->addItem(b);

    for (int i=0; i < listOfBuildings.size(); i++)
    {
        qDebug() << i;
    }
    // _scene->addItem(listOfBuildings[12]);

    //********************************************************************************

    listOfEvils.append(new Evil(500, 250));
    _scene->addItem(listOfEvils[0]);

    if (evil_flag == 1) {
        qDebug() << "fsdfdsf";
    }

    /*
    evil = new Evil(400,100);
    _scene->addItem(evil);
*/

    Player *pl = new Player(250, 230, 20);


    Bullet *bullet = new Bullet(pl->getX(), pl->getY());
    _scene->addItem(bullet);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(50);

    /*
    QTimer *timer2 = new QTimer(this);

    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(update()));

    timer2->start(100);
    qDebug() << "ovde";*/
/*
    QTimer *timer2 = new QTimer(this);
    QObject::connect(timer2, SIGNAL(timeout()), collision());

   // QObject::connect(timer2, SIGNAL(timeout()), _scene, SLOT(colision()));

    timer2->start(500);*/

}


bool Tokyo::collisionWithSmth(){
   /* QList<QGraphicsItem*> colliding_items = _fakePlayer->collidingItems();
    //qDebug() << colliding_items;
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items[i])) == typeid(Building))){
            //colliding_items.clear();
            return true;
        }
    }*/
    return false;
}

void Tokyo::update() {
    /*
    if(collisionWithBuildings() == true or collisionWithEvil() == true){
        _collision_detected = 1;
        qDebug() << _collision_detected;

    }*/

qDebug() << "usao u funkciju";
update();

}
