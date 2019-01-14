#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsItem>
#include <QPushButton>
#include <QGraphicsView>
#include "paris_utility.h"
#include "player.h"

/*
 * Klasa Building sluzi za pravljenje zgrada
 * koje se koriste u svakom nivou
 */

extern QString nameText;

static const int PLAYER_X = 250;
static const int PLAYER_Y = 230;
static const int PLAYER_STEP = 20;

class Building : public QObject, public QGraphicsItem{
        Q_OBJECT
public:

    Building(int xPos, int yPos, int width, int height, QString img, int bType);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void setName(QString name);

private:
    void advance(int step) override;

private:
    QString _img;
    int _width, _height;
    int _xPos, _yPos;
    QString _name;
    int _move_for = 0;
    int _move_for_up = 0;
    Player *player = new Player(PLAYER_X, PLAYER_Y, PLAYER_STEP);
    QList<QGraphicsItem*> listica;
    int _bType;
    int _move_by = 0;

};

#endif // BUILDING_H
