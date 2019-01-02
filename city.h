#ifndef CITY_H
#define CITY_H

#include "building.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>

class City : public QGraphicsView {

public:
    City(QString name);

    void setBackgraundImage(QString path);
    void setCityDimensions(int x, int y, int w, int h);

    virtual void buildCity() = 0;

protected:
    QGraphicsScene *m_scene;
    QList<Building*> listOfBuildings; // lista koja sadrzi sve gradjevine (treba ih cuvati zbog kasnije obrade kolizije sa njima)
    QString m_name;
    bool finished;
};

#endif // CITY_H
