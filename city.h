#ifndef CITY_H
#define CITY_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>

class City : public QGraphicsView {

public:
    City(QString name);

    void setBackgraundImage(QString path);
    void setCityDimensions(int x, int y, int w, int h);

    virtual void buildCity() = 0;

protected:
    QGraphicsScene *m_scene;
    QString m_name;
    bool finished;
};

#endif // CITY_H
