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
    void addQuestionAndAnswersToScene(QLabel *q, QPushButton *a1, QPushButton *a2, QPushButton *a3);
    void disableButtons(QPushButton *a1, QPushButton *a2, QPushButton *a3);

private slots:
    void answeredQuestion1True();
    void answeredQuestion2True();
    void answeredQuestion3True();
    void answeredQuestion4True();

    void answeredQuestion1False();
    void answeredQuestion2False();
    void answeredQuestion3False();
    void answeredQuestion4False();

    void finishedTest();

private:

    bool _testCorrect = false;
    ParisBuildingWindow *_testWindow;

    int _numOfQuestions = 4;
    int _numOfCorrectlyAnswered = 0;

    QPushButton *_btn1Correct;
    QPushButton *_btn1False1;
    QPushButton *_btn1False2;

    QPushButton *_btn2Correct;
    QPushButton *_btn2False1;
    QPushButton *_btn2False2;

    QPushButton *_btn3Correct;
    QPushButton *_btn3False1;
    QPushButton *_btn3False2;

    QPushButton *_btn4Correct;
    QPushButton *_btn4False1;
    QPushButton *_btn4False2;
};

#endif // PARIS_UTILITY_H
