#pragma once

#include <QLabel>
#include <QWidget>
#include <qevent.h>
#include <qdebug.h>
#include <QTimer>
#include <qpropertyanimation.h>

constexpr auto NUMBER_WIDTH = 30;
constexpr auto NUMBER_HEIGHT = 40;

static QString numberName[10] = { "0.png", "1.png" , "2.png" , "3.png" , "4.png"
,"5.png","6.png","7.png","8.png","9.png" };

struct Number_Data {
	int x;
	int y;
	int kind;							//元素的种类
};
class Number : public QLabel
{
	Q_OBJECT
public:
	int column;
	int row;
	QTimer *n_timer;
	Number(QWidget* parent, Number_Data d);
	~Number() {};
public slots:
	void timeUp();
};