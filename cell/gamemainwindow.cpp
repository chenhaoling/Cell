//开始界面
#include "mainwindow.h"
#include"gamemainwindow.h"
#include<QDebug>
gamemainwindow::gamemainwindow(QMainWindow *parent)
    : QMainWindow(parent)
{
    this->resize(891,510);
    this->setWindowTitle("Cell");
    this->setWindowIcon(QIcon(":/images/jiemian.jpg"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/jiemian.jpg")));
    this->setStyleSheet(":/images/background.jpg");
    this->setPalette(palette);
    startPush=new QPushButton(this);
    exitPush=new QPushButton(this);
    thanksPush=new QPushButton(this);
    startPush->setIconSize(QSize(90,45));
    startPush->setGeometry(400,300,90,45);
    startPush->setIcon(QIcon(":/images/Start.jpg"));
    startPush->setFlat(1);
    exitPush->setIconSize(QSize(90,45));
    exitPush->setGeometry(400,360,90,45);
    exitPush->setIcon(QIcon(":/images/Exit.jpg"));
    exitPush->setFlat(1);//设置按钮的透明属性
    thanksPush->setIconSize(QSize(90,45));
    thanksPush->setGeometry(400,420,90,45);
    thanksPush->setIcon(QIcon(":/images/thanks.jpg"));
    thanksPush->setFlat(1);
    exitBox=new QMessageBox;
    connect(exitPush,SIGNAL(clicked(bool)),this,SLOT(M_exitPush()));
    connect(startPush,SIGNAL(clicked(bool)),this,SLOT(~gamemainwindow()));
    connect(startPush,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));
    connect(thanksPush,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));
}


gamemainwindow::~gamemainwindow()
{
    delete this;
    exit(0);
}

void gamemainwindow::M_startPush()
{

    gamewindow=new MainWindow(this);  //创建一个新的界面，任然以原来的界面为父窗口，退出后可以直接回到上一个界面。
    gamewindow->show();

}

void gamemainwindow::M_exitPush()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Tips：","Do you want to leave the game?",QMessageBox::Yes|QMessageBox::No))
    {
        delete this;
        exit(0);
    }
}
