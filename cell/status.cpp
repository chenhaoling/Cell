#include "status.h"
#include<QColor>
Status::Status(const Wanwu &wanwu)
{
life=wanwu.life;
}

void Status::Display(QPainter &paint){
    paint.setPen(Qt::blue);
    paint.setFont(QFont("华文行楷",50));
    paint.drawText(10,50,QString("life:")+QString::number(life));

}
