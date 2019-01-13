#include "paris_utility.h"
#include <QLabel>
#include <QDebug>
#include <QGraphicsScene>
#include <QFile>

ParisBuildingWindow::ParisBuildingWindow(){
    _buildingScene = new QGraphicsScene();
    _buildingView = new QGraphicsView(_buildingScene);
    _btnExitBuilding = new QPushButton("Exit Building");
    _buildingView->setFixedSize(900, 700);
    _buildingScene->setSceneRect(0, 0, 900, 600);
}

void ParisBuildingWindow::setBackgraundImage(QString path){
    QImage *image = new QImage(path);
    QBrush *brush = new QBrush(image->scaled(_buildingView->size() * 1.27, Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    _buildingScene->setBackgroundBrush(*brush);
}

void ParisBuildingWindow::readAndWriteText(QString fileName, QString imagePath){

    QString text;
    QLabel *label = new QLabel();
    QFile inputFile(fileName);

    QString backgroundImage = "*{background-image: url(";
    backgroundImage.append(imagePath);
    backgroundImage.append(");}");
    label->setStyleSheet(backgroundImage);

    if (inputFile.open(QIODevice::ReadOnly)){

       QTextStream in(&inputFile);

       while (!in.atEnd()){
          QString line = in.readLine();
          text.append(line);
          text.append("\n");
       }

       inputFile.close();

       label->setText(text);
       _buildingScene->addWidget(label);
    }
}

void ParisBuildingWindow::arrangeScene(QString textPath, QString imagePath){

    if(textPath != ""){
        readAndWriteText(textPath, imagePath);
    }

    connect(_btnExitBuilding, SIGNAL(clicked()), this, SLOT(exitBuildingWindow()));

    _buildingView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _buildingView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    _btnExitBuilding->move(350, 550);
    _buildingScene->addWidget(_btnExitBuilding);
}

void ParisBuildingWindow::exitBuildingWindow(){
    _buildingView->close();
}


FinalTest::FinalTest(){
    _testWindow = new ParisBuildingWindow();
}

void FinalTest::makeTest(){
    _testWindow->arrangeScene("", "");

    QLabel *question1 = new QLabel("1. Between which years was the Triumphal arch built?");
    _btn1Correct = new QPushButton("1806. and 1836.");
    _btn1False1 = new QPushButton("1706. and 1736.");
    _btn1False2 = new QPushButton("1870. and 1920.");

    question1->move(30, 10);
    _btn1Correct->move(50, 40);
    _btn1False1->move(200, 40);
    _btn1False2->move(350, 40);

    QLabel *question2 = new QLabel("2. To whom, in particular, is the Triumphal arch dedicated?");
    _btn2Correct = new QPushButton("To those who fought during the Napoleonic Wars.");
    _btn2False1 = new QPushButton("To those who fought during World War I.");
    _btn2False2 = new QPushButton("To those who fought during Hundred Years' War.");

    question2->move(30, 90);
    _btn2Correct->move(50, 190);
    _btn2False1->move(50, 155);
    _btn2False2->move(50, 120);


    QLabel *question3 = new QLabel("3. What is the architectural style of Notre Dame?");
    _btn3Correct = new QPushButton("Gothic");
    _btn3False1 = new QPushButton("Romanesque");
    _btn3False2 = new QPushButton("Baroque");

    question3->move(30, 250);
    _btn3Correct->move(50, 280);
    _btn3False1->move(200, 280);
    _btn3False2->move(350, 280);

    addQuestionAndAnswersToScene(*question1, *_btn1Correct, *_btn1False1, *_btn1False2);
    addQuestionAndAnswersToScene(*question2, *_btn2Correct, *_btn2False1, *_btn2False2);
    addQuestionAndAnswersToScene(*question3, *_btn3Correct, *_btn3False1, *_btn3False2);

    /*
    _testWindow->_buildingScene->addWidget(question1);
    _testWindow->_buildingScene->addWidget(_btn1Correct);
    _testWindow->_buildingScene->addWidget(_btn1False1);
    _testWindow->_buildingScene->addWidget(_btn1False2);

    _testWindow->_buildingScene->addWidget(question2);
    _testWindow->_buildingScene->addWidget(_btn2Correct);
    _testWindow->_buildingScene->addWidget(_btn2False1);
    _testWindow->_buildingScene->addWidget(_btn2False2);
    */

    connect(_btn1Correct, SIGNAL(clicked()), this, SLOT(testSolvedCorrectly()));

    _testWindow->_buildingView->show();
}

void FinalTest::addQuestionAndAnswersToScene(QLabel &q, QPushButton &a1, QPushButton &a2, QPushButton &a3){
    _testWindow->_buildingScene->addWidget(&q);
    _testWindow->_buildingScene->addWidget(&a1);
    _testWindow->_buildingScene->addWidget(&a2);
    _testWindow->_buildingScene->addWidget(&a3);
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
