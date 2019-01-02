#include "player.h"

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
}

Player::~Player(){

}

/*
 * ispravljeno da player ne ide izvan okvira prozora
 * (dodati uslovi)
 */

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0) {
            setPos(x() - _step, y());
            this->setPixmap(_left);
        }
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 60 < 900) {
            this->setPixmap(_right);
            setPos(x() + _step, y());
        }
    }
    else if(event->key() == Qt::Key_Up){
        if (pos().y() > 0) {
            this->setPixmap(_left);
            setPos(x(), y() - _step);
        }
    }
    else if(event->key() == Qt::Key_Down){
        if (pos().y() + 110 < 599) {
        this->setPixmap(_right);
        setPos(x(), y() + _step);
        }
    }
}

