#include <QGraphicsPixmapItem>
#include "paris.h"


void Paris::buildCity(){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCityDimensions(0, 0, 900, 599);
    setBackgraundImage(":/images/images/paris_background6.jpg");

    /* Postavlja se ulica */
    makeStreet(":/images/images/paris_street_3.png", 400, 100, 0, 200);
    makeStreet(":/images/images/paris_street_4.png", 100, 100, 400, 200);
    makeStreet(":/images/images/paris_street_5.png", 100, 100, 400, 300);
    makeStreet(":/images/images/paris_street_3.png", 400, 100, 500, 300);
    makeStreet(":/images/images/paris_street_1.png", 100, 221, 250, 0);

    /* Postavljaju se zgrade */
    Building *eiffel = new Building(5,150, 300,300,":/images/images/paris_eiffel_tower.png");
    Building *notreDame = new Building(350,8, 150,200,":/images/images/paris_notre_dame2.jpg");
    Building *triumphalArch = new Building(10,8, 150,150,":/images/images/paris-triumphal-arch.svg");
    Building *key = new Building(100,80, 10,20,":/images/images/paris_key.png");
    Building *tree3 = new Building(320,55, 100,120,":/images/images/paris_tree3.png");
    Building *park = new Building(300,220, 200,120,":/images/images/paris_park.png");

    listOfBuildings.append(eiffel);
    listOfBuildings.append(triumphalArch);
    listOfBuildings.append(key);
    listOfBuildings.append(notreDame);
    listOfBuildings.append(tree3);
    listOfBuildings.append(park);

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


