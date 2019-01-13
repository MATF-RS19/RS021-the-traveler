#include "globalvars.h"
#include <QDebug>
#include "bullet.h"
#include "player.h"
#include <QTimer>
#include <QObject>
#include "london.h"

void London::buildSpecial(QJsonObject &json){

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    Player *pl = new Player(250, 230, 20);

    Bullet *bullet = new Bullet(pl->getX(), pl->getY());
    _scene->addItem(bullet);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(80);
}


bool London::collisionWithSmth(){
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

void London::update() {
    /*
    if(collisionWithBuildings() == true or collisionWithEvil() == true){
        _collision_detected = 1;
        qDebug() << _collision_detected;

    }*/

qDebug() << "usao u funkciju";
update();

}
