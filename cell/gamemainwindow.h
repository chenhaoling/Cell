#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H
#include "mainwindow.h"
#include<QPushButton>
#include<QMessageBox>

class gamemainwindow:public QMainWindow
{
    Q_OBJECT

public:
    gamemainwindow(QMainWindow*parent=0);
    QPushButton *startPush;
    QPushButton *exitPush;
    QPushButton *thanksPush;
    QMessageBox *exitBox;
    MainWindow  *gamewindow;
    ~gamemainwindow();
private slots:
    void M_startPush();
    void M_exitPush();
    //void M_thanksPush();
};
#endif // GAMEMAINWINDOW_H
