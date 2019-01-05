#ifndef PARIS_H
#define PARIS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>
#include "city.h"

class Paris : public City {


public:
    Paris()
        :City("Paris", 750, 250)
    {}

private slots:
    void findKey();

private:

    void buildCity();
    void makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos);
    Building *_key;
    bool _foundKey = false;

};

#endif // PARIS_H
