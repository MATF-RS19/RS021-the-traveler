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

Building::Building(int x, int y, QString img)
    : m_buildingSize(80), _img(img)
{
     setPos(x, y);
}

QRectF Building::boundingRect() const
{
    return QRectF(0,0,80,80);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    painter->drawRect(0,0,m_buildingSize,m_buildingSize);

    // slika gradjevine (trave...)
    QPixmap pixmap(_img);

    painter->drawPixmap(0, 0, 80, 80, pixmap);
}

void Building::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Building::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

