#include "london.h"
#include "tee.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>

London::London()
    : City("London", 0, 0, 20, 1)
{

}

void London::buildSpecial(QJsonObject &json)
{
    QJsonArray tees = json["tees"].toArray();

    foreach(const QJsonValue &tee, tees) {
        Tee * tea = new Tee(tee["x"].toInt(), tee["y"].toInt(), tee["w"].toInt(), tee["h"].toInt(),
                tee["src"].toString());
        _listOfTees.push_back(tea);
        _scene->addItem(tea);
    }

    connect(_player, SIGNAL(takeTee(QGraphicsItem *)), this, SLOT(removeTee(QGraphicsItem *)));
}


