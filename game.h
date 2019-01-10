#ifndef GAME_H
#define GAME_H

#include <QList>
#include "city.h"
#include "tokyo.h"
#include "paris.h"
#include <QMediaPlayer>

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

    void loadNextLevel();

/* goToNextLevel je slot koji prihvata signal o zavrsetku jednog nivoa i prelazi na naredni nivo koji mu se prosledjuje kao parametar. */
public slots:
    void goToNextLevel(int level);

private:
    QMediaPlayer * _music;
    QList<City*> listOfCities;
};



#endif // GAME_H
