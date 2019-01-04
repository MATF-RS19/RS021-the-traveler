#ifndef EVIL_H
#define EVIL_H

#include <QGraphicsItem>

class Evil : public QGraphicsItem
{
public:
    Evil(int x, int y);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int m_evilSize;
};

#endif // EVIL_H
