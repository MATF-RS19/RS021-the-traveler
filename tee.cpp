#include "tee.h"

#include <QPainter>

Tee::Tee(int xPos, int yPos, int width, int height, QString img)
    : _xPos(xPos), _yPos(yPos), _width(width), _height(height), _img(img)
{
    setPos(xPos, yPos);
}

QRectF Tee::boundingRect() const
{
    return QRectF(_xPos, _yPos, _width, _height);

}

void Tee::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap(_img);

    painter->drawPixmap(_xPos,_yPos,_width,_height, pixmap);
}
