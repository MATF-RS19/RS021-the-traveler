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
    //QVector<QString> text;
    QString text;
    QLabel *label = new QLabel();
    QFile inputFile(fileName);

    /*
    QPixmap pixmap(imagePath);
    label->setPixmap(pixmap);
    label->setMask(pixmap.mask());
    label->show();
    */

    QString backgroundImage = "*{background-image: url(";
    backgroundImage.append(imagePath);
    backgroundImage.append(");}");
    label->setStyleSheet(backgroundImage);

    //label->setText("<font color='red'>text</font>");
    //label->setStyleSheet("*{background-image: url(:/resources/img.png);}");


    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          text.append(line);
          text.append("\n");
          //text.push_back(line);
       }
       inputFile.close();
       /*
       QString coloredText = "<font color='white'>";
       coloredText.append(text);
       coloredText.append("</font>");
       label->setText(coloredText);
        */
       label->setText(text);
       _buildingScene->addWidget(label);
    }
}

void ParisBuildingWindow::arrangeScene(QString textPath, QString imagePath){

    if(textPath != ""){
        readAndWriteText(textPath, imagePath);
    }

    connect(_btnExitBuilding, SIGNAL(clicked()), this, SLOT(exitBuildingWindow()));

    //setBackgraundImage(imagePath);
    _buildingView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _buildingView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //QLabel *label = new QLabel();
    //label->setText(text);

    _btnExitBuilding->move(350, 550);
    //_buildingScene->addWidget(label);
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
