#include "tokyo.h"
#include "globalvars.h"
#include <QDebug>
#include "player.h"
#include <QTimer>
#include <QObject>

void Tokyo::buildSpecial(QJsonObject &json){

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    for (int i=0; i < listOfBuildings.size(); i++)
    {
        qDebug() << i;
    }

    listOfEvils.append(new Evil(730, 5));
    listOfEvils.append(new Evil(830, 190));
    listOfEvils.append(new Evil(750, 350));
    listOfEvils.append(new Evil(750, 470));
    _scene->addItem(listOfEvils[0]);
    _scene->addItem(listOfEvils[1]);
    _scene->addItem(listOfEvils[2]);
    _scene->addItem(listOfEvils[3]);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    timer->start(50);


    connect(_player, SIGNAL(escapedEvilObjects()), this, SLOT(finished()));

}
