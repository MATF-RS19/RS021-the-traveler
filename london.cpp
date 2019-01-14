#include "london.h"
#include "tee.h"
#include "londoneye.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QDebug>

static const int MSEC = 50;
static const int PLAYER_POS_X = 0;
static const int PLAYER_POS_Y = 0;
static const int STEP = 20;
static const int LEVEL_NUMBER = 1;

London::London()
    : City("London", PLAYER_POS_X, PLAYER_POS_Y, STEP, LEVEL_NUMBER)
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

    connect(_player, SIGNAL(takeSushi(QGraphicsItem *)), this, SLOT(removeSushi(QGraphicsItem *)));
    connect(this, SIGNAL(freeNextLevel()), _player, SLOT(toTheExit()) );
    connect(_player, SIGNAL(escapedEvilObjects()), this, SLOT(finished()));

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(MSEC);

}

void London::removeSushi(QGraphicsItem *item) {
    qDebug() << item->type();
    _scene->removeItem(item);
    numOfTees--;

    if(numOfTees == 0) {
        emit freeNextLevel();
    }
}
