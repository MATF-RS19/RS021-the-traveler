#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPathItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
    Player(int x, int y, int step);
    ~Player();


    void setPosition(int xPos, int yPos);
    void setStep(int step);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool collisionWithBuildings();
    bool collisionWithEvil();
    void checkLifes();
    QGraphicsPixmapItem *getFakePlayer();

    int getX();
    int getY();

    void setLevelNumber(int val);

/* escapedEvilObjects je signal koji se emituje kada plejer u prvom nivou uspe da pobegne objektima koji se pomeraju, izbegne Evel objekte i stigne do desne strane ekrana.
 * Game objekat treba da prihvati ovaj signal i da predje na naredni nivo.
 * Signale ne implementiramo posto su to virtualne funkcije koje, kada pozovemo sa emit, prosledjuju slotovima vrednosti svojih parametara.
*/
signals:
    void escapedEvilObjects(int level);

private:
    int _step;
    int _xPos, _yPos;
    QPixmap _left = QPixmap(":/images/images/left2.png");
    QPixmap _right = QPixmap(":/images/images/right2.png");
    bool collisionFlag = false;
    QGraphicsPixmapItem* _fakePlayer;
    QList<QGraphicsItem*> colliding_items2;
    int level_number;

public:
    int lifes = 3;
    int _collision_detected = 0;
};

#endif // PLAYER_H
