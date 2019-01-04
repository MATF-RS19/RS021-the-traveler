#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPathItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem {

public:
    Player(int x, int y);
    ~Player();
    void keyPressEvent(QKeyEvent *event);
    bool collisionWithBuildings();

    QGraphicsPixmapItem *getFakePlayer();

private:
    int _step = 3;
    int _xPos, _yPos;
    QPixmap _left = QPixmap(":/images/images/left2.png");
    QPixmap _right = QPixmap(":/images/images/right2.png");
    bool collisionFlag = false;
    QGraphicsPixmapItem* _fakePlayer;
};

#endif // PLAYER_H
