#include "evil.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>
#include "game.h"
#include <QRectF>
#include <QPainter>
#include <QPixmap>

Evil::Evil(int x, int y)
    : m_evilSize(80)
{
     setPos(x, y);
}

QRectF Evil::boundingRect() const
{
    return QRectF(0,0,80,80);
}

void Evil::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    //painter->drawRect(0,0,m_evilSize,m_evilSize);
    QPixmap pixmap(":/images/images/sushi2.png");

    painter->drawPixmap(0, 0, 80, 80, pixmap);

}

void Evil::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Evil::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}



