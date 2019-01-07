#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPathItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QGraphicsPixmapItem {
    //Q_OBJECT
public:
    Player(int x, int y);
    ~Player();
    void keyPressEvent(QKeyEvent *event);
    bool collisionWithBuildings();
    bool collisionWithEvil();
    void checkLifes();
    QGraphicsPixmapItem *getFakePlayer();

    int getX();
    int getY();

//public slots:
    void keyReleaseEvent(QKeyEvent *event);

   // void collision();


private:
    int _step = 30;      // ubrzala sam je! bilo je step = 3
    int _xPos, _yPos;
    QPixmap _left = QPixmap(":/images/images/left2.png");
    QPixmap _right = QPixmap(":/images/images/right2.png");
    bool collisionFlag = false;
    QGraphicsPixmapItem* _fakePlayer;
    QList<QGraphicsItem*> colliding_items2;
public:
    int lifes = 3;
    int _collision_detected = 0;
};

#endif // PLAYER_H
