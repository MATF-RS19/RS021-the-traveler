#ifndef PARIS_H
#define PARIS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>
#include "city.h"

class Paris : public City {
    Q_OBJECT

public:
    Paris()
        :City("Paris", 750, 250, 3, 1)
    {}

    void buildSpecial(QJsonObject &json);


public slots:
    void isFinished();
    //void findKey();

private:
    void makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos);
    Building *_key;
    bool _foundKey = false;

};

#endif // PARIS_H
