#include "projectwidget.h"
#include "database.h"
#include <QApplication>
database databs;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    databs.databaseinit();
    w.run();
    return a.exec();
}
