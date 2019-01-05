#include "building.h"
#include "game.h"
#include <QRectF>
#include <QPainter>
#include <QPixmap>

    /*
     *
     * TODO: sredicu kod... bice bez brojeva...
     *
     */

Building::Building(int xPos, int yPos, int width, int height, QString img)
    : _xPos(xPos), _yPos(yPos), _width(width), _height(height), _img(img)
{
     setPos(xPos, yPos);
}

QRectF Building::boundingRect() const
{
    return QRectF(_xPos,_yPos,_width,_height);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    painter->drawRect(_xPos,_yPos,_width,_height);

    // slika gradjevine (trave...)
    QPixmap pixmap(_img);

    painter->drawPixmap(_xPos,_yPos,_width,_height, pixmap);
}

void Building::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Building::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

