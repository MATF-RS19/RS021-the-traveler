#ifndef TEE_H
#define TEE_H

#include <QGraphicsItem>

class Tee : public QGraphicsItem
{
public:
    Tee(int xPos, int yPos, int width, int height, QString img);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

private:
    int _xPos;
    int _yPos;
    int _width;
    int _height;
    QString _img;
};

#endif // TEE_H
