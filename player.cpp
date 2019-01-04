#include "player.h"
#include "building.h"
#include <QGraphicsScene>
#include <QDebug>
#include "evil.h"
#include "globalvars.h"
#include "city.h"
#include "game.h"
#include <QGraphicsView>
#include <QGraphicsItem>

extern int a;
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
    _fakePlayer->setScale(0.6);

}

Player::~Player(){

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        _fakePlayer->setPos(x() - _step, y());
        checkLifes();
        if(collisionWithBuildings() == false && collisionWithEvil() == false){
            if (pos().x() > 0) {
                setPos(x() - _step, y());
                this->setPixmap(_left);
            }
        }
    }
    else if(event->key() == Qt::Key_Right){
        _fakePlayer->setPos(x() + _step, y());
        checkLifes();
        if(collisionWithBuildings() == false && collisionWithEvil() == false){
            if (pos().x() + 60 < 900) {
                this->setPixmap(_right);
                setPos(x() + _step, y());
            }
        }
    }
    else if(event->key() == Qt::Key_Up){
        _fakePlayer->setPos(x(), y() - _step);
        checkLifes();
        if(collisionWithBuildings() == false && collisionWithEvil() == false){
            if (pos().y() > 0) {
                this->setPixmap(_left);
                setPos(x(), y() - _step);
            }
        }
    }
    else if(event->key() == Qt::Key_Down){
        _fakePlayer->setPos(x(), y() + _step);
        checkLifes();
        if(collisionWithBuildings() == false && collisionWithEvil() == false){
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

bool Player::collisionWithEvil(){
    colliding_items2 = _fakePlayer->collidingItems();
    //qDebug() << colliding_items;
    int n = colliding_items2.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items2[i])) == typeid(Evil))){
            //colliding_items.clear();
            return true;
        }
    }
    return false;
}

void Player::checkLifes() {
    if (collisionWithEvil() == true and lifes > 0) {
        this->setOpacity(this->opacity() - 0.2);
        lifes = lifes - 1;

// ne dirajte ovo! :D
        //   evil_flag = 1;
       //     scene()->removeItem(colliding_items2[0]);
        //    delete colliding_items2[0];

    }

    if (lifes <= 0) {
        a = 1 +a;
        //qDebug() << a;
       // Game::listOfCities[1]->show();

    }

}

