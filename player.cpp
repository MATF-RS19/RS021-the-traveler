#include "player.h"
#include "building.h"
#include <QGraphicsScene>
#include <QDebug>

    /*
     * DIMENZIJE PLAYERA:
     * 110 x 60
     *
     */

Player::Player(int x, int y){
    _xPos = x;
    _yPos = y;
    this->setPos(_xPos,_yPos);
    this->setPixmap(_left);

    /* Da bi objekat mogao da odreaguje na neki event mora da se fokusira. Ovo nam je potrebno za kretanje. */
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    _fakePlayer = new QGraphicsPixmapItem;
    _fakePlayer->setPos(_xPos,_yPos);
    _fakePlayer->setPixmap(QPixmap(":/images/images/fake-player.png"));

}

Player::~Player(){

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        _fakePlayer->setPos(x() - _step, y()+50);
        if(collisionWithBuildings() == false){
            if (pos().x() > 0) {
                setPos(x() - _step, y());
                this->setPixmap(_left);
            }
        }
    }
    else if(event->key() == Qt::Key_Right){
        _fakePlayer->setPos(x() + _step+5, y()+50);
        if(collisionWithBuildings() == false){
            if (pos().x() + 60 < 900) {
                this->setPixmap(_right);
                setPos(x() + _step, y());
            }
        }
    }
    else if(event->key() == Qt::Key_Up){
        _fakePlayer->setPos(x(), y() - _step);
        if(collisionWithBuildings() == false){
            if (pos().y() > 0) {
                this->setPixmap(_left);
                setPos(x(), y() - _step);
            }
        }
    }
    else if(event->key() == Qt::Key_Down){
        _fakePlayer->setPos(x(), y() + _step+70);
        if(collisionWithBuildings() == false){
            if (pos().y() + 110 < 599) {
            this->setPixmap(_right);
            setPos(x(), y() + _step);
            }
        }
    }
}


QGraphicsPixmapItem *Player::getFakePlayer(){
    return _fakePlayer;
}

bool Player::collisionWithBuildings(){
    QList<QGraphicsItem*> colliding_items = _fakePlayer->collidingItems();
    //qDebug() << colliding_items;
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items[i])) == typeid(Building))){
            //colliding_items.clear();
            return true;
        }
    }
    return false;
}

