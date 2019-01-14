#include "building.h"
#include "game.h"
#include <QRectF>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <math.h>
#include <QDebug>

FinalTest *testParis;
static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;
static const int X_CENTER_OF_ROTATION = 450;
static const int Y_CENTER_OF_ROTATION = 80;
static const int RADIUS = 70;
static const int MAX_MOVE_FOR = 500;
static const int ANGLE_CONST = 100;

Building::Building(int xPos, int yPos, int width, int height, QString img, int type)
    : _img(img), _width(width), _height(height), _xPos(xPos), _yPos(yPos), _bType(type)
{
     setPos(xPos, yPos);
}

QRectF Building::boundingRect() const
{
    return QRectF(_xPos,_yPos,_width,_height);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
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
        notreDameInterior->arrangeScene(":/text/text/NotreDame.txt", ":/images/images/paris_notre_dame_interior2.jpg");
        notreDameInterior->_buildingView->show();
    }
    else if(_name == "Triumphal arch"){
        ParisBuildingWindow * triumphalArchInterior = new ParisBuildingWindow();
        triumphalArchInterior->arrangeScene(":/text/text/TriumphalArch.txt", ":/images/images/paris_triumph2.jpg");
        triumphalArchInterior->_buildingView->show();
    }
}

void Building::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void Building::setName(QString name){
    _name = name;
}

void Building::advance(int step) {

    if(_bType != 0){
        if (_move_for < MAX_MOVE_FOR) {
            if (_bType == 1) {
                _move_for += 1;
                setPos(_xPos, _yPos + _move_for);
            }
        }
        else {
                _move_for = 0;
        }

        if (_move_for_up < MAX_MOVE_FOR) {
            if (_bType == 2) {
                _move_for_up += 1;
                setPos(_xPos, _yPos - _move_for_up);
            }
        }
        else {
                _move_for_up = 0;
        }

        if(_bType == 3){
             _move_by += 1;
             double theta = TWO_PI * _move_by / ANGLE_CONST;// racuna trenutni ugao
             _xPos = int(X_CENTER_OF_ROTATION + RADIUS * cos(theta));
             _yPos = int(Y_CENTER_OF_ROTATION + RADIUS * sin(theta));
             setPos((_xPos), (_yPos));
        }

        QList<QGraphicsItem*> colliding_items3 = this->collidingItems();
        int n = colliding_items3.size();
        for(int i = 0; i < n; ++i){
            if((typeid(*(colliding_items3[i])) == typeid(Player))){
                //colliding_items3.clear();
                QMessageBox msgBox;
                msgBox.setInformativeText(nameText + ", the box just hit you!");
                QPushButton* myButton =new QPushButton("Exit game!");
                msgBox.addButton(myButton ,QMessageBox::AcceptRole);
                QObject::connect(myButton,&QPushButton::pressed,[](){ QApplication::exit(); });
                msgBox.exec();
            }
        }
        update();
    }
}
