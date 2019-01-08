#ifndef CITY_H
#define CITY_H

#include "building.h"
#include "evil.h"
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
//#include <qtglobal.h>

class City : public QGraphicsView {

public:
    City(QString name, int playerPosX, int playerPosY, int level_number);
    ~City();

    void setBackgraundImage(QString path);
    void setCityDimensions(int x, int y, int w, int h);

    QString getName();
    //bool ifFinished();

    void buildBasic(const QJsonObject &jsonObj, const QString &img, const QJsonArray &buildings);
    virtual void buildSpecial(QJsonObject &json) = 0;
    /*extern*/ QList<Evil*> listOfEvils;

    void moveToNextLevel();

protected:
    QGraphicsScene *_scene;
    QList<Building*> listOfBuildings; // lista koja sadrzi sve gradjevine (treba ih cuvati zbog kasnije obrade kolizije sa njima)
   // QList<Evil*> listOfEvils;
    QString _name;
    bool _finished;     // bolje ovde da bude nego u svakom gradu pojedinacno
public:
    Player *_player;
    int _level_number;
};

#endif // CITY_H
