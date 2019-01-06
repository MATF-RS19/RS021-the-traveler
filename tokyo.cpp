#include "tokyo.h"
#include "globalvars.h"
#include <QDebug>
#include "bullet.h"
#include "player.h"

void Tokyo::buildCity(){

    setCityDimensions(0, 0, 900, 599);
    setBackgraundImage(":/images/images/chinese-pattern-background.jpg");

    // create our object and add it to the scene
    listOfBuildings.append(new Building(0,0,80,80, ":/images/images/tokyo_grass.png"));   // kordinate gornjeg levog ugla
    //m_scene->addItem(listOfBuildings.takeAt(0));
    listOfBuildings.append(new Building(70,0,80,80, ":/images/images/Plant01-2.png"));
    listOfBuildings.append(new Building(140,0,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(210,0,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(340,0,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(410,0,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(480,0,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(550,0,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(620,0,80,80, ":/images/images/Building06.png"));
    listOfBuildings.append(new Building(750,0,80,80, ":/images/images/Building06.png"));
    listOfBuildings.append(new Building(820,0,80,80, ":/images/images/tokyo_grass.png"));
/*
    listOfBuildings.append(new Building(0,170, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(70,170, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(140,170, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(210,170, ":/images/images/Building01.png"));
    listOfBuildings.append(new Building(340,170, ":/images/images/Building06.png"));
    listOfBuildings.append(new Building(410,170, ":/images/images/Building06.png"));
    listOfBuildings.append(new Building(480,170, ":/images/images/Building05.png"));
    listOfBuildings.append(new Building(550,170, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(620,170, ":/images/images/Building04.png"));
    listOfBuildings.append(new Building(750,170, ":/images/images/Building06.png"));
    listOfBuildings.append(new Building(820,170, ":/images/images/tokyo_grass.png"));
*/
    listOfBuildings.append(new Building(0,340,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(70,340,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(140,340,80,80, ":/images/images/tokyo_building_type_2.png"));
   // listOfBuildings.append(new Building(210,340, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(340,340,80,80, ":/images/images/Building05.png"));
    listOfBuildings.append(new Building(410,340,80,80, ":/images/images/Building05.png"));
    listOfBuildings.append(new Building(480,340,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(550,340,80,80, ":/images/images/Building05.png"));
    listOfBuildings.append(new Building(620,340,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(750,340,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(820,340,80,80, ":/images/images/tokyo_grass.png"));

    listOfBuildings.append(new Building(0,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(70,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(140,510,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(210,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(340,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(410,510,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(480,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(550,510,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(620,510,80,80, ":/images/images/tokyo_grass.png"));
    listOfBuildings.append(new Building(750,510,80,80, ":/images/images/tokyo_building_type_2.png"));
    listOfBuildings.append(new Building(820,510,80,80, ":/images/images/tokyo_grass.png"));

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    //*******************************************************************************
    // TODO
    // PROBLEM:
    // svi objekti (buildings) su u listi listOfBuildings ali se NE PRIKAZUJU na sceni!

    foreach(Building *b, listOfBuildings) _scene->addItem(b);

    for (int i=0; i < listOfBuildings.size(); i++)
    {
        qDebug() << i;
    }
    // _scene->addItem(listOfBuildings[12]);

    //********************************************************************************

    listOfEvils.append(new Evil(500, 250));
    _scene->addItem(listOfEvils[0]);

    if (evil_flag == 1) {
        qDebug() << "fsdfdsf";
    }

    /*
    evil = new Evil(400,100);
    _scene->addItem(evil);
*/

    Player *pl = new Player(250, 230);


    Bullet *bullet = new Bullet(pl->getX(), pl->getY());
    _scene->addItem(bullet);

}
