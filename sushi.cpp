#include "sushi.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>
#include "game.h"
#include <QRectF>
#include <QPainter>
#include <QPixmap>

Sushi::Sushi(int x, int y)
    : _sushiSize(80)
{
     setPos(x, y);
}

QRectF Sushi::boundingRect() const
{
    return QRectF(0,0,80,80);
}

void Sushi::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap(":/images/images/sushi2.png");
    painter->drawPixmap(0, 0, 80, 80, pixmap);
}

void Sushi::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Sushi::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}
