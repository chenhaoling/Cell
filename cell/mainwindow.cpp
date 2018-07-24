#include "mainwindow.h"
#include"QRect"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   //
    QFont font;
    font.setPointSize(100);
    paint.setFont(font);
    paint.setPen(QColor(255,0,0));
    //初始发全局结构体
    glo.framei=0;
    glo.status=new Status();
    glo.blockimage=new QImage(":/images/map_block.png");
    glo.tankimage=new QImage(":/images/player_tank.png");
    glo.bulletimage=new QImage(":/images/bullet.png");
    glo.gamemap=new GameMap();
    glo.player=new Tank();
    Tank *tmp=new Tank(2,3,UP,5);
    glo.badtanks.append(tmp);
    tmp=new Tank(2,5,DOWN,3);
    glo.badtanks.append(tmp);
    //
    gamestatus=gameing;
    laststyle=0;
    leftorright=1;
    timer=new QTimer(this);
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefun()));
    timer->start();
    this->setWindowTitle("Cell");

}

MainWindow::~MainWindow()
{
timer->stop();
delete timer;


}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

setFixedSize(WIDTH,HEIGHT);

paint.begin(this);
glo.gamemap->Display(paint);
glo.player->Display(paint);
glo.status->Display(paint);
for(int i=0;i<glo.badtanks.count();i++)
glo.badtanks.at(i)->Display(paint);

paint.end();
}




void MainWindow::keyPressEvent(QKeyEvent *event){
    qDebug("key:--------------------------%d ",event->key());
//当按键为M时设置游戏状态为mapedit
    if(event->key()==Qt::Key_M)
        {
            gamestatus=mapedit;
        }else if(event->key()==Qt::Key_G){
            gamestatus=gameing;
        }

    if(gamestatus==mapedit){
        if(event->key()==Qt::Key_S)
            {

                 glo.gamemap->savemap("1.dat");
             }
        else if(event->key()==Qt::Key_L)
            {

                glo.gamemap->loadmap("1.dat");
             }

     }else if(gamestatus==gameing){
          if(event->key()==Qt::Key_S)
             {

                 glo.player->setdir(DOWN);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_A)
            {

                 glo.player->setdir(LEFT);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_W)
             {
               glo.player->setdir(UP);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_D)
          {
              glo.player->setdir(RIGHT);glo.player->startmove();

          }else if(event->key()==Qt::Key_J){

                 glo.player->startfire();

          }


     }
update();
}



void MainWindow::keyReleaseEvent(QKeyEvent *event){


   if(event->key()==Qt::Key_J)
   glo.player->stopfire();
   else
       glo.player->stopmove();

}



void MainWindow::timefun(){
  if(gamestatus!=gameing)return;
    glo.framei++;
    Dir tmpdir;int tmp;
/**敌人坦克控制**/
    for(int i=0;i<glo.badtanks.count();i++){
    if(qrand()%5==0)
    {glo.badtanks.at(i)->startmove();glo.badtanks.at(i)->startfire();}
   if(qrand()%10==0)
       glo.badtanks.at(i)->stopmove();

   if(qrand()%10==0)
       glo.badtanks.at(i)->stopfire();


   if(qrand()%10==0){
       tmp=qrand()%4;
          switch(tmp){
          case 0:
              tmpdir=UP;
            break;
          case 1:
              tmpdir=DOWN;
            break;

           case 2:
              tmpdir=LEFT;
              break;

          case 3:
              tmpdir=RIGHT;
              break;




          }
         glo.badtanks.at(i)->setdir(tmpdir);
           }
    }

 /**end**/




glo.player->Move();
glo.player->fire();
for(int i=0;i<glo.badtanks.count();i++)
{glo.badtanks.at(i)->Move();glo.badtanks.at(i)->fire();}

qDebug("timeout");
update();
}
