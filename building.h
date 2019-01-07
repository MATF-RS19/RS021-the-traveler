#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsItem>
#include <QPushButton>
#include <QGraphicsView>
#include "paris_utility.h"


class Building : public QObject, public QGraphicsItem{
        Q_OBJECT
public:
    Building(int xPos, int yPos, int width, int height, QString img);
    ~Building();

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void setName(QString name);


private:
    QString _img;
    int _width, _height;
    int _xPos, _yPos;
    QString _name;

};

#endif // BUILDING_H
