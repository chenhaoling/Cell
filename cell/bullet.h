#ifndef BULLET_H
#define BULLET_H
#include"all.h"
#include"cell.h"
class Bullet : public Wanwu
{
public:
    Bullet(const Tank &tank);
    // 绘图
  void Display(QPainter &paint) ;

    // 移动
    void Move() ;
    //
protected:
    void CalculateSphere();
private:
    int style;
    int group;//子弹所在组

};

#endif // BULLET_H
