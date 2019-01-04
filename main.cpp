#include "mainmenuwindow.h"
#include <QApplication>
#include "evil.h"

int a;

int main(int argc, char *argv[])
{
    a = 0;
    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();

    return a.exec();
}
