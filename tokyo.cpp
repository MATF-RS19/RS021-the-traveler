#include "tokyo.h"

void Tokyo::buildCity(){

    setCityDimensions(0, 0, 900, 599);
    setBackgraundImage(":/images/images/chinese-pattern-background.jpg");

    // create our object and add it to the scene
    listOfBuildings.append(new Building(100,100));   // kordinate gornjeg levog ugla
    //m_scene->addItem(listOfBuildings.takeAt(0));
    listOfBuildings.append(new Building(180,100));
    // m_scene->addItem(listOfBuildings.takeAt(1));
    listOfBuildings.append(new Building(260,100));
    // m_scene->addItem(listOfBuildings.takeAt(2));

    /*
     * postavlja item-e na scenu
     * (koje redom uzima iz liste)
     */

    foreach(Building *b, listOfBuildings) _scene->addItem(b);
}
