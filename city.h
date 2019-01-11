#ifndef CITY_H
#define CITY_H

#include "building.h"
#include "evil.h"
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
//#include <qtglobal.h>

class City : public QGraphicsView {
    Q_OBJECT
public:
    City(QString name, int playerPosX, int playerPosY, int playerStep, int level_number);
    QGraphicsScene * getScene();
    ~City();

    QList <Building *> getListOfBuildings() const;

    void setBackgraundImage(QString path);
    void setCityDimensions(int x, int y, int w, int h);


    void buildBasic(const QJsonObject &jsonObj, const QString &img, const QJsonArray &buildings, Player * player);
    virtual void buildSpecial(QJsonObject &json) = 0;

    QString getName();
    Player* getPlayer();

    /*extern*/ QList<Evil*> listOfEvils;
    bool setFinished(bool val);


public slots:
    void callNextLevel(int level);
signals:
    void goToNextLevel(int level);

protected:
    QGraphicsScene *_scene;
    QList<Building*> _listOfBuildings;
   // QList<Evil*> listOfEvils;
    QString _name;
    bool _finished;
    Player *_player;
public:
    //Player *_player;
    int _level_number;

};

#endif // CITY_H
