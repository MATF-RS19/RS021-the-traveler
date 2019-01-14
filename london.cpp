#include "london.h"
#include "tee.h"
#include "londoneye.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QDebug>

London::London()
    : City("London", 0, 0, 20, 1)
{

}

void London::buildSpecial(QJsonObject &json)
{
    QJsonArray tees = json["tees"].toArray();

    foreach(const QJsonValue &tee, tees) {
        _scene->addItem(new Tee(tee["x"].toInt(), tee["y"].toInt(), tee["w"].toInt(), tee["h"].toInt(),
                tee["src"].toString()));
    }

    QJsonArray londonEyes = json["london-eye"].toArray();
    foreach(const QJsonValue &londonEye, londonEyes) {
        qDebug() << londonEye["x"].toInt();
        _scene->addItem(new LondonEye(londonEye["x"].toInt(), londonEye["y"].toInt(), londonEye["w"].toInt(), londonEye["h"].toInt(),
                londonEye["src"].toString()));
    }

    connect(_player, SIGNAL(takeTee(QGraphicsItem *)), this, SLOT(removeTee(QGraphicsItem *)));

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(50);

}


