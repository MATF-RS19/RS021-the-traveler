#ifndef PARISBUILDING_H
#define PARISBUILDING_H

#include "building.h"
#include <QPushButton>

class ParisBuilding : public Building{

public:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

private:
    QPushButton *exit = new QPushButton("exit");
};

#endif // PARISBUILDING_H
