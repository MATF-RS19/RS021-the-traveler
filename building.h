#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsItem>

class Building : public QGraphicsItem
{
public:
    Building(int xPos, int yPos, int width, int height, QString img);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString _img;
    int _width, _height;
    int _xPos, _yPos;
};

#endif // BUILDING_H
