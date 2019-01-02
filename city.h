#ifndef CITY_H
#define CITY_H

#include "building.h"
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>

class City : public QGraphicsView {

public:
    City(QString name, int playerPosX, int playerPosY);

    void setBackgraundImage(QString path);
    void setCityDimensions(int x, int y, int w, int h);

    virtual void buildCity() = 0;

protected:
    QGraphicsScene *_scene;
    QList<Building*> listOfBuildings; // lista koja sadrzi sve gradjevine (treba ih cuvati zbog kasnije obrade kolizije sa njima)
    QString _name;
    bool _finished;     // bolje ovde da bude nego u svakom gradu pojedinacno
    Player *_player;
};

#endif // CITY_H
