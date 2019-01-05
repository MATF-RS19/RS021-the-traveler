#include <QGraphicsPixmapItem>
#include "paris.h"


void Paris::buildCity(){

    setCityDimensions(0, 0, 900, 599);
    setBackgraundImage(":/images/images/paris_background6.jpg");

    /* Postavlja se ulica */
    makeStreet(":/images/images/paris_street_3.png", 400, 100, 0, 200);
    makeStreet(":/images/images/paris_street_4.png", 100, 100, 400, 200);
    makeStreet(":/images/images/paris_street_5.png", 100, 100, 400, 300);
    makeStreet(":/images/images/paris_street_3.png", 400, 100, 500, 300);
    makeStreet(":/images/images/paris_street_1.png", 100, 221, 250, 0);

    /* Postavljaju se zgrade */
    Building *eiffel = new Building(600,10, ":/images/images/paris_eiffel_tower.png");
    //eiffel->boundingRect();
    QRectF newRect = QRectF(eiffel->x(), eiffel->y(), 400, 600);
    eiffel->update(newRect);
    listOfBuildings.append(eiffel);

    foreach(Building *b, listOfBuildings) _scene->addItem(b);

}

void Paris::makeStreet(QString imgPath, int xScale, int yScale, int xPos, int yPos){
    QGraphicsPixmapItem *street = new QGraphicsPixmapItem();
    QPixmap *streetImage = new QPixmap(imgPath);
    *streetImage = streetImage->scaled(xScale, yScale);
    street->setPixmap(*streetImage);
    street->setPos(xPos, yPos);
    street->setZValue(-1);
    _scene->addItem(street);
}


