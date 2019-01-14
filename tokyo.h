#ifndef TOKYO_H
#define TOKYO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "city.h"
#include "sushi.h"
#include "player.h"

static const int PLAYER_POS_X = 10;
static const int PLAYER_POS_Y = 450;
static const int STEP = 20;
static const int LEVEL_NUMBER = 0;

class Tokyo : public City {
public:
    Tokyo()
        :City("Tokyo", PLAYER_POS_X, PLAYER_POS_Y, STEP, LEVEL_NUMBER)
    {}

    void buildSpecial(QJsonObject &json);
    void removeFood(QGraphicsItem *item);

signals:
    void goToNextLevel(int level);

private:
    int numOfSushi = 4;
};

#endif // TOKYO_H
