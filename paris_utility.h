#ifndef PARIS_UTILITY_H
#define PARIS_UTILITY_H

#include <QGraphicsView>
#include <QPushButton>


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

//private slots:

public slots:
    void testSolvedCorrectly();
    bool notifyParis();

public:
    FinalTest();
    void makeTest();

    bool _testCorrect = false;
    ParisBuildingWindow *_testWindow;

    QPushButton *_btnCorrect;
    QPushButton *_btnFalse;
};

#endif // PARIS_UTILITY_H
