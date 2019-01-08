#ifndef GAME_H
#define GAME_H

#include <QList>
#include "city.h"
#include "tokyo.h"
#include "paris.h"

extern int change_now;


/*
    Ova klasa sadrzi listu gradova koje igrac treba da obidje
    i metod kojim se pokrece igra u tim gradovima.
*/

class Game : public QObject {
    Q_OBJECT

public:
    Game();
    void start();

    Paris *paris;
    Tokyo *tokyo;

private slots:
    void goToNextLevel(int level);

private:
    QList<City*> listOfCities;
};

#endif // GAME_H
