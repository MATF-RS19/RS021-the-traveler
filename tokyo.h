#ifndef TOKYO_H
#define TOKYO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "city.h"
#include "evil.h"
#include "player.h"

class Tokyo : public City {
public:
    Tokyo()
        :City("Tokyo", 250, 230, 20, 0)
    {}

    void buildSpecial(QJsonObject &json);


    void update();
    bool collisionWithSmth();
signals:
    void goToNextLevel(int level);
private:
    bool restart_level = false;
};

#endif // TOKYO_H
