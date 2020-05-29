#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_UI.h"
#include <qdebug.h>
#include "Icon.h"
#include "myhelper.h"
#include <QTime>  
#include <QTimer>
#include<QEventloop>

class UI : public QMainWindow
{
	Q_OBJECT

public:
	UI(QWidget *parent = Q_NULLPTR);
	void iconExplode(Icon* icon);
public slots:
	void iconClicked();
	void iconReleased();
	void iconSwap(int dir);
	void timeUp();
	void on_pushButton_clicked();
private:
	Ui::UIClass ui;
	Icon*** icons;
	MyHelper helper;
	void initIcons(int row, int column);	
	void swap(int row1, int column1, int row2, int column2);
	std::vector<Icon*> getPoints(int row, int column);
	void sleep(int sleepTime);
	QTimer* timer;
	QEventLoop Wait;
	//void initRowBeta(Icon***);
	//void initColumnBeta(Icon***);
	int m_time;//����ʱʱ��
	int random;//�����
	bool iswait = false;
	QString initime;
};

