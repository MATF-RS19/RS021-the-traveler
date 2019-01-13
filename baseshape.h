#ifndef BASESHAPE_H
#define BASESHAPE_H

    /*
     *
     * TODO: doraditi...
     *
     * Ova klasa je zamisljena kao osnovna klasa za oblike
     * dorada ove klase zavisi od toga kakve cemo vrste itema imati
     * tj. po cemu ce se razlikovati
     *
     * npr. ako ce se itemi razlikovati po obliku, onda klasu baseshape treba
     * da nasledi klasa rectangle i triangle (ako cemo imati samo ta dva oblika itema)
     * ... osnovni oblici vec postoje, ali zbog kolizije... drugacije ce se obradjivati
     * kolizija za pravougaonike, a drugacije za trouglove
     *
     * ako se itemi razlikuju po nekoj drugoj osobini, onda klasu baseshape
     * treba da naslede klase X koja ima osobinu1, osobinu2
     * i klasa Y koja nema te osobine ali ima osobinu3, osobinu4
     * gde X i Y imaju zajednicke osobine osobina5, osobina6, osobina7
     *
     */

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>

class BaseShape :public QGraphicsItem {
public:
    BaseShape();

    QRectF boundingRect() const;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    // item state
    bool Pressed;
protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BASESHAPE_H
