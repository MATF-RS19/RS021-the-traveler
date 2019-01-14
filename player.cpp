#include "player.h"
#include "building.h"
#include <QGraphicsScene>
#include <QDebug>
#include "sushi.h"
#include "globalvars.h"
#include "city.h"
#include "game.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include "bullet.h"
#include "tee.h"

Player::Player(int x, int y, int step){
    _xPos = x;
    _yPos = y;
    _step = step;
    this->setPos(_xPos,_yPos);
    this->setPixmap(_left);

    /*
     * Da bi objekat mogao da odreaguje na neki event mora da se fokusira.
     * Ovo nam je potrebno za kretanje.
     */

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
        if(collisionWithBuildings() == false){
            if (pos().x() > 0) {
                setPos(x() - _step, y());
                this->setPixmap(_left);
                //collisionWithTees();
            }
        }
    }
    else if(event->key() == Qt::Key_Right){
        _fakePlayer->setPos(x() + _step, y());
        checkLifes();
        if(collisionWithBuildings() == false){
            if (pos().x() + 60 < 900) {
                this->setPixmap(_right);
                setPos(x() + _step, y());
                //collisionWithTees();
            }

            /*
             * Ako se plejer nalazi na nivou 0, tj u Tokiu,
             * i uspeo je da popegne Evel objektima i dodje do desne strane
             * prozora, onda se emituje signal za prelazak u naredni nivo.
             */
            if (pos().x() + 60 >= 900 && pos().y() > 400 and _toTheExit == true) {
                qDebug() << "to the exit" ;//){  // donji desni ugao
                emit escapedEvilObjects();
            }
        }
    }
    else if(event->key() == Qt::Key_Up){
        _fakePlayer->setPos(x(), y() - _step);
        checkLifes();
        if(collisionWithBuildings() == false) { //&& collisionWithEvil() == false){
            if (pos().y() > 0) {
                this->setPixmap(_left);
                setPos(x(), y() - _step);
                //collisionWithTees();
            }
        }
    }
    else if(event->key() == Qt::Key_Down){
        _fakePlayer->setPos(x(), y() + _step);
        checkLifes();
        if(collisionWithBuildings() == false) {// && collisionWithEvil() == false){
            if (pos().y() + 110 < 599) {
                this->setPixmap(_right);
                setPos(x(), y() + _step);
                //collisionWithTees();
            }
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if((event->key() == Qt::Key_Left) ||
       (event->key() == Qt::Key_Right) ||
       (event->key() == Qt::Key_Up) ||
       (event->key() == Qt::Key_Down)){

        _xPos = x();
        _yPos = y();
    }
}


QGraphicsPixmapItem *Player::getFakePlayer(){
    return _fakePlayer;
}

int Player::getX(){
    return _xPos;
}

int Player::getY(){
    return _yPos;
}
/*
void Player::collisionWithTees() {
    QList<QGraphicsItem*> colliding_items = _fakePlayer->collidingItems();
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items[i])) == typeid(Tee))) {
            emit takeTee(colliding_items[i]);
        }
    }
}

void Player::collisionWithSushi() {
    QList<QGraphicsItem*> colliding_items = _fakePlayer->collidingItems();
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items[i])) == typeid(Sushi))) {
            emit takeSushi(colliding_items[i]);
        }
    }
}
*/
bool Player::collisionWithBuildings() {
    QList<QGraphicsItem*> colliding_items = _fakePlayer->collidingItems();
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items[i])) == typeid(Building))){
            return true;
        }
    }
    return false;
}

bool Player::collisionWithEvil(){
    colliding_items2 = _fakePlayer->collidingItems();
    int n = colliding_items2.size();
    for(int i = 0; i < n; ++i){
        if((typeid(*(colliding_items2[i])) == typeid(Sushi))){
            emit takeSushi(colliding_items2[i]);
        }
        if((typeid(*(colliding_items2[i])) == typeid(Tee))){
            emit takeSushi(colliding_items2[i]);
        }
    }
    return false;
}

void Player::checkLifes() {
    if (collisionWithEvil() == true and lifes > 0) {
        //colliding_items2[0]->setPos(-200, -200);
        food ++;

       //     scene()->removeItem(colliding_items2[0]);
       //    delete colliding_items2[0];
    }
}

void Player::toTheExit() {
    _toTheExit = true;
}
