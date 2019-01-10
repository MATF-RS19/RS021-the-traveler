#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include "player.h"

class Bullet: public QGraphicsRectItem {
public:
    Bullet(int x, int y);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event);
    void setName(QString name);

private:
    int _x_coord;
    int _y_coord;
    QString _name;
    Player *p = new Player(250, 230, 20);
};

#endif // BULLET_H
