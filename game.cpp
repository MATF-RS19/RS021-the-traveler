#include "game.h"
#include "paris.h"

#include <iterator>

Game::Game(){

    Paris *paris = new Paris();
    listOfCities.push_back(paris);
}

void Game::start(){

    /*
        Ovim metodom se prave i prikazuju gradovi iz liste.
    */


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

    for(it = listOfCities.begin(); it != listOfCities.end(); it++){
        (*it)->show();
    }

    //listOfCities[0]->show();
}
