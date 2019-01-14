#ifndef LONDON_H
#define LONDON_H

#include "city.h"
#include "tee.h"
#include <QList>

class London : public City
{
public:
    London();

    void buildSpecial(QJsonObject &json);
    void removeFood(QGraphicsItem *item);

private:
    int numOfTees = 10;
};

#endif // LONDON_H
