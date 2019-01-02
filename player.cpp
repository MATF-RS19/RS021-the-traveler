#include "player.h"

Player::Player(int x, int y){
    _xPos = x;
    _yPos = y;
    this->setPos(_xPos,_yPos);
    this->setPixmap(_left);
    /* Da bi objekat mogao da odreaguje na neki event mora da se fokusira. Ovo nam je potrebno za kretanje. */
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

Player::~Player(){

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        setPos(x() - _step, y());
        this->setPixmap(_left);
    }
    else if(event->key() == Qt::Key_Right){
        this->setPixmap(_right);
        setPos(x() + _step, y());
    }
    else if(event->key() == Qt::Key_Up){
        this->setPixmap(_left);
        setPos(x(), y() - _step);
    }
    else if(event->key() == Qt::Key_Down){
        this->setPixmap(_right);
        setPos(x(), y() + _step);
    }
}

