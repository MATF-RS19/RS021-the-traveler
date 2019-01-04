#include "mainmenuwindow.h"
#include <QApplication>
#include "evil.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();

    return a.exec();
}
