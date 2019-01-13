#ifndef LONDON_H
#define LONDON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "city.h"
#include "evil.h"
#include "player.h"

class London : public City {
public:
    London()
        :City("London", 250, 230, 20, 0)
    {}

    void buildSpecial(QJsonObject &json);
    void update();
    bool collisionWithSmth();
private:
    bool restart_level = false;
};


#endif // LONDON_H
