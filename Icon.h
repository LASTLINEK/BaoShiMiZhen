#pragma once

#include <QLabel>
#include <QWidget>
#include <qevent.h>
#include <qdebug.h>
#include <qpropertyanimation.h>
constexpr auto ICON_WIDTH = 60;			
constexpr auto ICON_HEIGHT = 60;		
constexpr auto UP = 8;		
constexpr auto DOWN = 2;		
constexpr auto LEFT = 4;		
constexpr auto RIGHT = 6;		
static QString pixFileName[6] = { "k1.png", "k2.png" , "k3.png" , "k4.png" , "k5.png","boom.png" };
struct Data {
    int x;
    int y;
    int kind;							//元素的种类
};

enum UnitStatus{  //单元样式枚举
    status_init = 0 , //初始状态
    status_deleted = -1, //被删除状态
    status_blue = 1, //样式例子 （待补充）
};

class Icon : public QLabel
{
    Q_OBJECT

signals:
    void Clicked();
    void Released();
    void Swap(int direction);
public:
    int column;
    int row;
    int status;
	int iconkind;
    Icon(QWidget * parent, Data d);
    ~Icon() {};
    void swapWith(Icon* i);
    void drop(int blocks);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
private:
    //QString m_str;
    int originX;
    int originY;
    bool swapping;
};
