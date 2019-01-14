#ifndef LONDONEYE_H
#define LONDONEYE_H

#include <QGraphicsItem>

class LondonEye: public QGraphicsItem
{
public:
    LondonEye(int xPos, int yPos, int width, int height, QString img, int radius);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void advance(int step) override;

private:
    int _xPos;
    int _yPos;
    int _width;
    int _height;
    QString _img;
    double _angle;
    double _radius;
    double _move;
    double _xCenter;
    double _yCenter;
} ;

#endif // LONDONEYE_H
