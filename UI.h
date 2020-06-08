#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_UI.h"
#include <qdebug.h>
#include "Icon.h"
#include "myhelper.h"
#include <QTime>  
#include <QTimer>
#include "music.h"
#include<QEventloop>
#include "orderview.h"

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

private slots:

	void on_orderBtn_clicked();


    void on_musicButton_clicked();

private:
	Ui::UIClass ui;
	Icon*** icons;
     Music music;
	MyHelper helper;
    int random = 0;
    bool isPause;
    QIcon musicicon;
	void drop_tmp(int row, int col);
	void initIcons(int row, int column);	

    bool swapAndDelete(int row1, int column1, int row2, int column2);
    void swap(int row1, int column1, int row2, int column2);

	std::vector<Icon*> getPoints(int row, int column);
	void sleep(int sleepTime);

	QTimer* timer;
	QEventLoop Wait;
	int m_time;
	bool iswait = false;
	QString initime;

	bool CheckMapDead(int,int);
    std::vector<Icon*> Hint(int,int );
    bool DropUnit(int row, int column);
    void RandomAdd(int row, int column);  
    bool AutoDelete(int row,int column);
	void freshMap(int row, int column);
public:
	OrderView* v;

};
