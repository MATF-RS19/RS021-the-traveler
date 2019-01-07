#include "paris_utility.h"
#include <QLabel>
#include <QDebug>


ParisBuildingWindow::ParisBuildingWindow(){
    _buildingScene = new QGraphicsScene();
    _buildingView = new QGraphicsView(_buildingScene);
    _btnExitBuilding = new QPushButton("Exit Building");
    _buildingView->setFixedSize(800, 600);
    _buildingScene->setSceneRect(0, 0, 800, 600);
}

void ParisBuildingWindow::arrangeScene(QString text){

    connect(_btnExitBuilding, SIGNAL(clicked()), this, SLOT(exitBuildingWindow()));

    QLabel *label = new QLabel();
    label->setText(text);
    _btnExitBuilding->move(300, 300);
    _buildingScene->addWidget(label);
    _buildingScene->addWidget(_btnExitBuilding);
}

void ParisBuildingWindow::exitBuildingWindow(){
    _buildingView->close();
}


FinalTest::FinalTest(){
    _testWindow = new ParisBuildingWindow();
}

void FinalTest::makeTest(){
    _testWindow->arrangeScene("");

    QLabel *question1 = new QLabel("First Question?");
    _btnCorrect = new QPushButton("Correct answer");
    _btnFalse = new QPushButton("False answer");

    question1->move(50, 50);
    _btnCorrect->move(50, 100);
    _btnFalse->move(200, 100);

    _testWindow->_buildingScene->addWidget(question1);
    _testWindow->_buildingScene->addWidget(_btnCorrect);
    _testWindow->_buildingScene->addWidget(_btnFalse);

    connect(_btnCorrect, SIGNAL(clicked()), this, SLOT(testSolvedCorrectly()));

    _testWindow->_buildingView->show();
}

void FinalTest::testSolvedCorrectly(){
    _testCorrect = true;
    notifyParis();
    qDebug() << "testSolvedCorrect";
    _testWindow->_buildingView->close();
}

bool FinalTest::notifyParis(){
    qDebug() << "utility - notifyParis";
}
