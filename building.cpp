#include "building.h"
#include "game.h"
#include <QRectF>
#include <QPainter>
#include <QPixmap>
#include <QLabel>

FinalTest *testParis;


Building::Building(int xPos, int yPos, int width, int height, QString img)
    : _xPos(xPos), _yPos(yPos), _width(width), _height(height), _img(img)
{
     setPos(xPos, yPos);
}

Building::~Building(){
    //_buildingScene->clear();
}


QRectF Building::boundingRect() const
{
    return QRectF(_xPos,_yPos,_width,_height);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // crtanje pravougaonika
    painter->drawRect(_xPos,_yPos,_width,_height);

    // slika gradjevine (trave...)
    QPixmap pixmap(_img);

    painter->drawPixmap(_xPos,_yPos,_width,_height, pixmap);
}

void Building::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(_name == "Eiffel"){
        testParis = new FinalTest();
        testParis->makeTest();

    }
    else if(_name == "Notre Dame"){
        ParisBuildingWindow * notreDameInterior = new ParisBuildingWindow();
        notreDameInterior->arrangeScene("The Notre Dame cathedral is widely considered to be one of the finest examples of French Gothic architecture.");
        notreDameInterior->_buildingView->show();
    }
}

void Building::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void Building::setName(QString name){
    _name = name;
}


