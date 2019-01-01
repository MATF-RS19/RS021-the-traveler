#ifndef PARIS_H
#define PARIS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "city.h"

class Paris : public City {
public:
    Paris()
        :City("Paris")
    {}

private:

    void buildCity();
    //bool finished;    // indikator koji govori da li je igrac uradio sve sto treba u trenutnom gradu kako bi presao u novi
                        // trenutno zakomentarisano dok se ne naprave svi gradovi
};

#endif // PARIS_H
