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
        :City("Tokyo", 10, 450, 20, 0)
    {}

    void buildSpecial(QJsonObject &json);

signals:
    void goToNextLevel(int level);
};

#endif // TOKYO_H
