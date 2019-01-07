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
        :City("Tokyo", 250, 230)
    {}

    void buildSpecial(QJsonObject &json);

    void update();
    bool collisionWithSmth();
private:
    bool restart_level = false;
   // Evil * evil;
    //void buildCity();
    //bool finished;
//    Player *player = new Player(250, 230);
};

#endif // TOKYO_H
