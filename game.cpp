#include "game.h"
#include "paris.h"
#include "tokyo.h"
#include <QDebug>
#include <iterator>
#include "player.h"



extern int a;


Game::Game(){

    Paris *paris = new Paris();
    Tokyo *tokyo = new Tokyo();
    listOfCities.push_back(tokyo);
    listOfCities.push_back(paris);
}

void Game::start(){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */

  qDebug() << a;
    qDebug() << listOfCities[0]->_player->lifes;

    QList<City*>::iterator it;
    for(it = listOfCities.begin(); it != listOfCities.end(); it++){
        (*it)->buildCity();
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

    listOfCities[1]->show();
}



