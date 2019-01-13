#include "paris_utility.h"
#include <QLabel>
#include <QDebug>
#include <QGraphicsScene>
#include <QFile>
#include <QMessageBox>
#include <QApplication>

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

    _btnExitBuilding->move(400, 550);
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

    QLabel *question4 = new QLabel("4. During whose reign were grand organ placed in Notre Dame?");
    _btn4Correct = new QPushButton("Louis XIII");
    _btn4False1 = new QPushButton("Henry IV");
    _btn4False2 = new QPushButton("Louis XV");

    question4->move(30, 350);
    _btn4Correct->move(50, 380);
    _btn4False1->move(200, 380);
    _btn4False2->move(350, 380);

    addQuestionAndAnswersToScene(question1, _btn1Correct, _btn1False1, _btn1False2);
    addQuestionAndAnswersToScene(question2, _btn2Correct, _btn2False1, _btn2False2);
    addQuestionAndAnswersToScene(question3, _btn3Correct, _btn3False1, _btn3False2);
    addQuestionAndAnswersToScene(question4, _btn4Correct, _btn4False1, _btn4False2);

    QPushButton *btnFinishedTest = new QPushButton("Finished test!");
    btnFinishedTest->move(400, 500);
    _testWindow->_buildingScene->addWidget(btnFinishedTest);


    connect(_btn1Correct, SIGNAL(clicked()), this, SLOT(answeredQuestion1True()));
    connect(_btn2Correct, SIGNAL(clicked()), this, SLOT(answeredQuestion2True()));
    connect(_btn3Correct, SIGNAL(clicked()), this, SLOT(answeredQuestion3True()));
    connect(_btn4Correct, SIGNAL(clicked()), this, SLOT(answeredQuestion4True()));

    connect(_btn1False1, SIGNAL(clicked()), this, SLOT(answeredQuestion1False()));
    connect(_btn1False2, SIGNAL(clicked()), this, SLOT(answeredQuestion1False()));

    connect(_btn2False1, SIGNAL(clicked()), this, SLOT(answeredQuestion2False()));
    connect(_btn2False2, SIGNAL(clicked()), this, SLOT(answeredQuestion2False()));

    connect(_btn3False1, SIGNAL(clicked()), this, SLOT(answeredQuestion3False()));
    connect(_btn3False2, SIGNAL(clicked()), this, SLOT(answeredQuestion3False()));

    connect(_btn4False1, SIGNAL(clicked()), this, SLOT(answeredQuestion4False()));
    connect(_btn4False2, SIGNAL(clicked()), this, SLOT(answeredQuestion4False()));

    connect(btnFinishedTest, SIGNAL(clicked()), this, SLOT(finishedTest()));

    _testWindow->_buildingView->show();
}

void FinalTest::addQuestionAndAnswersToScene(QLabel *q, QPushButton *a1, QPushButton *a2, QPushButton *a3){
    _testWindow->_buildingScene->addWidget(q);
    _testWindow->_buildingScene->addWidget(a1);
    _testWindow->_buildingScene->addWidget(a2);
    _testWindow->_buildingScene->addWidget(a3);
}

void FinalTest::disableButtons(QPushButton *a1, QPushButton *a2, QPushButton *a3){
    a1->setEnabled(false);
    a2->setEnabled(false);
    a3->setEnabled(false);
}


void FinalTest::answeredQuestion1True(){
    disableButtons(_btn1Correct, _btn1False1, _btn1False2);
    _numOfCorrectlyAnswered++;
}

void FinalTest::answeredQuestion2True(){
    disableButtons(_btn2Correct, _btn2False1, _btn2False2);
    _numOfCorrectlyAnswered++;
}

void FinalTest::answeredQuestion3True(){
    disableButtons(_btn3Correct, _btn3False1, _btn3False2);
    _numOfCorrectlyAnswered++;
}

void FinalTest::answeredQuestion4True(){
    disableButtons(_btn4Correct, _btn4False1, _btn4False2);
    _numOfCorrectlyAnswered++;
}

void FinalTest::answeredQuestion1False(){
    disableButtons(_btn1Correct, _btn1False1, _btn1False2);
}

void FinalTest::answeredQuestion2False(){
    disableButtons(_btn2Correct, _btn2False1, _btn2False2);
}

void FinalTest::answeredQuestion3False(){
    disableButtons(_btn3Correct, _btn3False1, _btn3False2);
}

void FinalTest::answeredQuestion4False(){
    disableButtons(_btn4Correct, _btn4False1, _btn4False2);
}

void FinalTest::finishedTest(){
    _testWindow->_buildingView->close();
    QMessageBox msgBox;
    if(_numOfCorrectlyAnswered == _numOfQuestions){
        msgBox.setInformativeText("You answered all questions correctly and finished game!");
        QPushButton* myButton =new QPushButton("Exit game!");
        msgBox.addButton(myButton ,QMessageBox::AcceptRole);
        QObject::connect(myButton,&QPushButton::pressed,[](){ QApplication::exit(); });
    }
    else{
        msgBox.setInformativeText("You haven't answered all questions correctly. Please try again.");
        QPushButton* myButton =new QPushButton("Close");
        msgBox.addButton(myButton ,QMessageBox::AcceptRole);
        QObject::connect(myButton,&QPushButton::pressed,[&msgBox, this](){ msgBox.close(); _testWindow->_buildingView->close();});
    }
    msgBox.exec();

}
