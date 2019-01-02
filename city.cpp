#include "city.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QSize>

City::City(QString name){
    m_name = name;
    m_scene = new QGraphicsScene();
    setScene(m_scene);
    finished = false;

}

    /*
     * izmenjen metod za postavljanje pozadine
     * jer prethodni nije imao mogucnost skaliranja slike
     * (prethodni kod je zakomentarisan)
     */

void City::setBackgraundImage(QString path){
   // setBackgroundBrush(QBrush(QImage(path)));

    QImage *image = new QImage(path);
    QBrush *brush = new QBrush(image->scaled(this->size(),Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    setBackgroundBrush(*brush);
}


void City::setCityDimensions(int x, int y, int w, int h){
    /*
     * Postavljaju se dimenzije i pozicija grada, tj. scene u kojoj ce biti prikazan grad.
     * I dimenzije pogleda se postavljaju na iste vrednosti, kako bismo imali pogled na celu scenu.
     */
    m_scene->setSceneRect(x, y, w, h);
    setFixedSize(w, h);
}
