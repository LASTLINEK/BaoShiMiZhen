#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UI.h"
#include <qdebug.h>
#include "Icon.h"
#include "myhelper.h"
//#include <QTime>
#include <time.h>

class UI : public QMainWindow
{
	Q_OBJECT

public:
	UI(QWidget *parent = Q_NULLPTR);
public slots:
	void iconClicked();
	void iconReleased();
	void iconSwap(int dir);
private:
	Ui::UIClass ui;
	Icon*** icons;
	MyHelper helper;
	void initIcons(int row, int column);	
	void swap(int row1, int column1, int row2, int column2);
    void initRowBeta(Icon***);
    void initColumnBeta(Icon***);
	std::vector<Icon*> getPoints(int row, int column);
    //QTime time;
	int random = 0;//Ëæ»úÊý
};
