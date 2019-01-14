#ifndef PARIS_H
#define PARIS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>
#include "city.h"

static const int PLAYER_POS_X_PARIS = 750;
static const int PLAYER_POS_Y_PARIS = 250;
static const int STEP_PARIS = 3;
static const int LEVEL_NUMBER_PARIS = 2;

class Paris : public City {
    Q_OBJECT

public:
    Paris()
        :City("Paris", PLAYER_POS_X_PARIS, PLAYER_POS_Y_PARIS, STEP_PARIS, LEVEL_NUMBER_PARIS)
    {}

    void buildSpecial(QJsonObject &json);
    void removeSushi(QGraphicsItem *item);

private:
    void makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos);


};

#endif // PARIS_H
