#include "main.h"
#include "gamemainwindow.h"
#include "mainwindow.h"
#include <QApplication>
Glo glo;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gamemainwindow w;
    w.setWindowTitle("Cell");
    w.show();
    return a.exec();
}
