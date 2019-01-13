#include "bullet.h"
#include <QPainter>

Bullet::Bullet(int x, int y)
    : _x_coord(x), _y_coord(y)
{
    setRect(0, 0, 10, 50);
}


QRectF Bullet::boundingRect() const
{
    return QRectF(_x_coord,_y_coord, /*width*/ 80, /*height*/ 80);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    // painter->drawRect(_x_coord, _y_coord, 80, 80);
    painter->drawRect(_x_coord, _y_coord, 80, 80);
}

void Bullet::mousePressEvent(QGraphicsSceneMouseEvent *event){

}

void Bullet::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void Bullet::setName(QString name){
    _name = name;
}


void Bullet::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        _x_coord = p->getX();
        _y_coord = p->getY();
    }
}
