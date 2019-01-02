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

Building::Building(int x, int y)
    : m_buildingSize(80)
{
     setPos(x, y);
}

QRectF Building::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    painter->drawRect(0,0,m_buildingSize,m_buildingSize);

    // slika gradjevine (trave...)
    QPixmap pixmap(":/images/images/tokyo_grass.png");

    painter->drawPixmap(-10, -10, 100, 100, pixmap);
}

void Building::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Building::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

