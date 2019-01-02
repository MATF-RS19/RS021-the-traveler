#ifndef TOKYO_H
#define TOKYO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "city.h"

class Tokyo : public City {
public:
    Tokyo()
        :City("Tokyo")
    {}

private:

    void buildCity();
    //bool finished;
};

#endif // TOKYO_H
