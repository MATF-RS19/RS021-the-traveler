#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsItem>

class Building : public QGraphicsItem
{
public:
    Building(int x, int y);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int m_buildingSize;
};

#endif // BUILDING_H
