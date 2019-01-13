#include "tokyo.h"
#include "globalvars.h"
#include <QDebug>
#include "player.h"
#include <QTimer>
#include <QObject>

void Tokyo::buildSpecial(QJsonObject &json){

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    for (int i=0; i < listOfBuildings.size(); i++)
    {
        qDebug() << i;
    }

    listOfEvils.append(new Evil(500, 250));
    _scene->addItem(listOfEvils[0]);


    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(50);


    connect(_player, SIGNAL(escapedEvilObjects()), this, SLOT(finished()));

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
