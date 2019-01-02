#include "baseshape.h"

/*
 *
 * Procitati o ovoj klasi u baseshape.h!
 *
 */

BaseShape::BaseShape()
{
}

QRectF BaseShape::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void BaseShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void BaseShape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    // radi nesto...
}

void BaseShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    // radi nesto...
}
