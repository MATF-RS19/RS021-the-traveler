#ifndef PARIS_UTILITY_H
#define PARIS_UTILITY_H

#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>

class ParisBuildingWindow : public QObject {
    Q_OBJECT

private slots:
    void exitBuildingWindow();

public:

    ParisBuildingWindow();
    void arrangeScene(QString textPath, QString imagePath);
    void setBackgraundImage(QString path);
    void readAndWriteText(QString fileName, QString imagePath);

    QPushButton *_btnExitBuilding;
    QGraphicsScene *_buildingScene;
    QGraphicsView *_buildingView;

};

class FinalTest : public QObject {
        Q_OBJECT

public:
    FinalTest();
    void makeTest();
    void addQuestionAndAnswersToScene(QLabel &q, QPushButton &a1, QPushButton &a2, QPushButton &a3);

public slots:
    void testSolvedCorrectly();
    bool notifyParis();

private:

    bool _testCorrect = false;
    ParisBuildingWindow *_testWindow;

    QPushButton *_btn1Correct;
    QPushButton *_btn1False1;
    QPushButton *_btn1False2;

    QPushButton *_btn2Correct;
    QPushButton *_btn2False1;
    QPushButton *_btn2False2;

    QPushButton *_btn3Correct;
    QPushButton *_btn3False1;
    QPushButton *_btn3False2;
};

#endif // PARIS_UTILITY_H
