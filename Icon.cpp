#include "Icon.h"

Icon::Icon(QWidget * parent, Data d):QLabel(parent)
{
    this->setGeometry(d.x, d.y, ICON_WIDTH, ICON_HEIGHT);
	QPixmap pix(pixFileName[d.kind]);
	status =d.kind ;  //初始化状态
    originX = 0;
    originY = 0;
    
    swapping = false;
    this->setPixmap(pix);
    this->setScaledContents(true);
    this->show();
}

void Icon::swapWith(Icon *& i)
{
    int tempCol = i->column;
    int tempRow = i->row;
    i->column = this->column;
    i->row = this->row;
    qDebug() << this->row << "," << this->column << " swap with " << tempRow << "," << tempCol;
    this->column = tempCol;
    this->row = tempRow;
    QPropertyAnimation* aniThis = new QPropertyAnimation(this, "geometry");
    QPropertyAnimation* aniThat = new QPropertyAnimation(i, "geometry");
    QRect geometry1 = this->geometry();
    QRect geometry2 = i->geometry();
    qDebug() << geometry1;
    qDebug() << geometry2;
    aniThis->setStartValue(geometry1);
    aniThat->setStartValue(geometry2);
    aniThis->setEndValue(geometry2);
    aniThat->setEndValue(geometry1);

    aniThis->setDuration(300);
    aniThat->setDuration(300);
    aniThis->start();
    aniThat->start();

    this->setGeometry(geometry2);
    i->setGeometry(geometry1);
}

void Icon::drop(int blocks)
{
    QPropertyAnimation* ani = new QPropertyAnimation(this, "geometry");
    ani->setDuration(500);
    ani->setStartValue(this->geometry());
    int endX = this->x();
    int endY = 100+ (blocks+row)* ICON_HEIGHT;
    originY += ICON_HEIGHT;
    ani->setKeyValueAt(0.75, QRect(endX, endY, ICON_WIDTH, ICON_HEIGHT));
    ani->setKeyValueAt(0.9, QRect(endX, endY - 15, ICON_WIDTH, ICON_HEIGHT));
    ani->setEndValue(QRect(endX, endY, ICON_HEIGHT, ICON_HEIGHT));
    ani->start();
    QRect geometry = this->geometry();
    int y = geometry.y();
    geometry.setY(y + blocks * ICON_HEIGHT);
}

void Icon::refresh(int kind)
{
    QPixmap pix(pixFileName[kind]);
    status = kind;  //初始化状态
    this->setGeometry(100+column*ICON_WIDTH, 100+row*ICON_HEIGHT, ICON_WIDTH, ICON_HEIGHT);
    this->setPixmap(pix);
    this->setScaledContents(true);
    this->setVisible(true);
}

void Icon::setSwapping(bool tf)
{
    if (tf) {
        swapping = true;
    }
    else {
        swapping = false;
    }
}

void Icon::mouseMoveEvent(QMouseEvent * event)
{
    if (swapping) {
        return;
    }
    int endX = event->globalX();
    int endY = event->globalY();
    bool shouldSwap = false;
    if (endX > originX + ICON_WIDTH) {
        shouldSwap = true;
        emit Swap(RIGHT);
    }
    else if (endX < originX - ICON_WIDTH) {
        shouldSwap = true;
        emit Swap(LEFT);
    }
    else if (endY > originY + ICON_HEIGHT) {
        shouldSwap = true;
        emit Swap(DOWN);
    }
    else if (endY < originY - ICON_WIDTH) {
        shouldSwap = true;
        emit Swap(UP);
    }
    if (shouldSwap) {
        qDebug() << "siganal sent";
        //swapping = true;
        originX = endX;
        originY = endY;
    }
}

void Icon::mousePressEvent(QMouseEvent * e)
{
    originX = e->globalX();
    originY = e->globalY();
    emit Clicked();
}

void Icon::mouseReleaseEvent(QMouseEvent * event)
{
    //swapping = false;
    emit Released();
}
