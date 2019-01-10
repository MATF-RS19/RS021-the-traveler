#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsItem>
#include <QPushButton>
#include <QGraphicsView>
#include "paris_utility.h"
#include "player.h"

extern int change_now;

class Building : public QObject, public QGraphicsItem{
        Q_OBJECT
public:

    Building(int xPos, int yPos, int width, int height, QString img, int bType);
    ~Building();

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void setName(QString name);

    void up();
    void down();

    void advance(int step) override;


private:
    QString _img;
    int _width, _height;
    int _xPos, _yPos;
    QString _name;
    int _move_for = 0;
    int _move_for_up = 0;
    Player *player = new Player(250, 230, 20);
    QList<QGraphicsItem*> listica;
    int _bType;

};

#endif // BUILDING_H
