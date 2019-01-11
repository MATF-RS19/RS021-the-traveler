#ifndef GAME_H
#define GAME_H

#include <QList>
#include "city.h"
#include "tokyo.h"
#include "paris.h"
#include <QMediaPlayer>
#include <QString>
#include "player.h"

extern int change_now;


/*
    Ova klasa sadrzi listu gradova koje igrac treba da obidje
    i metod kojim se pokrece igra u tim gradovima.
*/

class Game : public QGraphicsScene {
    Q_OBJECT

public:
    Game(QGraphicsView * view);
    ~Game();
    void start(int level);

    int getLevel() const;

    Paris *paris;
    Tokyo *tokyo;

    void loadNextLevel();

/* goToNextLevel je slot koji prihvata signal o zavrsetku jednog nivoa i prelazi na naredni nivo koji mu se prosledjuje kao parametar. */
public slots:
    void goToNextLevel(int level);

private:
    void setBackground(const QString img);
    QGraphicsView * _view;
    QMediaPlayer * _music;
    QList<City*> _listOfCities;
    Player * _player;

    int _level;
};



#endif // GAME_H
