#include "game.h"
#include "paris.h"
#include "tokyo.h"
#include <QDebug>
#include <iterator>
#include "player.h"
#include "myqfile.h"

#include <QMediaPlayer>
#include <QJsonArray>

extern int a;


Game::Game(){

    Paris *paris = new Paris();
    Tokyo *tokyo = new Tokyo();
    listOfCities.push_back(tokyo);
    //listOfCities.push_back(paris);
}

void Game::start(){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */

  qDebug() << a;
    qDebug() << listOfCities[0]->_player->lifes;
    QMediaPlayer * music = new QMediaPlayer();

    QList<City*>::iterator it;
    for(it = listOfCities.begin(); it != listOfCities.end(); it++){
        QString fileName = ":/json/" + (*it)->getName() + ".json";
        qDebug() << fileName;
        myQfile f(fileName);
        QJsonDocument cityD = f.makeJSONDoc();

        QJsonArray buildings = cityD["buildings"].toArray();
        (*it)->buildBasic(cityD["dimensions"].toObject(), cityD["background"].toString(), buildings);

        QJsonObject obj = cityD["special"].toObject();
        (*it)->buildSpecial(obj);

        QString musicUrl = cityD["music"].toString();
        qDebug() << musicUrl;
        music->setMedia(QUrl(musicUrl));
        music->play();

    }


    /*
        TODO:
        Prikazati grad ako je atribut grada finished = false
        Kad finished postane true, uraditi close() tog grada i tek onda preci u sledeci iz liste.
        Zasad, dok se pravi grad, zakomentarisati petlju ispod i otvarati prozor sa:
        listOfCities[i]->show();
    */

    /*
    for(it = listOfCities.begin(); it != listOfCities.end(); it++){
        (*it)->show();
    }
*/
    /*
    listOfCities[0]->show();
    qDebug() << listOfCities[0]->_player->lifes;
qDebug() << a;
    if (listOfCities[0]->_player->lifes <= 0) {
         // listOfCities[0]->invalidateScene();
         // listOfCities[1]->show();
         qDebug() << "sdssa";
         listOfCities[1]->show();
    }
    */


    /* OVako se otvore svi gradovi
     * for(it = listOfCities.begin(); it != listOfCities.end(); it++) {
        (*it)->show();
        if((*it)->ifFinished())
            (*it)->close();

    }*/

    listOfCities[0]->show();
}



