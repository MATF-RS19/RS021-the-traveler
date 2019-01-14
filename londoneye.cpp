#include "londoneye.h"
#include "player.h"

#include <math.h>

#include <QPainter>
#include <QMessageBox>
#include <QPushButton>
#include <QApplication>
#include <QtDebug>

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;
static const int ANGLE_CONST = 300;

LondonEye::LondonEye(int xPos, int yPos, int width, int height, QString img)
    :_xPos(xPos), _yPos(yPos), _width(width), _height(height), _img(img), _radius(80), _xCenter(200), _yCenter(100)
{
    setPos(xPos, yPos);
}

QRectF LondonEye::boundingRect() const
{
    return QRectF(_xPos, _yPos, _width, _height);

}

void LondonEye::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap(_img);

    painter->drawPixmap(_xPos,_yPos,_width,_height, pixmap);
}

void LondonEye::advance(int step) {
    _move += 1;
    _angle = TWO_PI * _move / ANGLE_CONST;

    _xPos = int(_xCenter + _radius * cos(_angle));
    _yPos = int(_yCenter + _radius * sin(_angle));

    setPos(_xPos, _yPos);

    QList <QGraphicsItem *> collidingitems = this->collidingItems();

    for(QGraphicsItem * item: collidingitems)
        if((typeid(*(item)) == typeid(Player))){
            //colliding_items3.clear();
            QMessageBox msgBox;
            msgBox.setInformativeText("London eye has just killed you :(");
            QPushButton * myButton = new QPushButton("Exit game!");
            msgBox.addButton(myButton , QMessageBox::AcceptRole);
            QObject::connect(myButton, &QPushButton::pressed,
                             [] () { QApplication::exit(); });
            msgBox.exec();
        }
}
