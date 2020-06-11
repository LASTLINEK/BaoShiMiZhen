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
#include "number.h"
#include<QStack>
#include "help.h"

class UI : public QMainWindow
{
	Q_OBJECT

public:
    UI(int s=10,QWidget *parent = Q_NULLPTR);
    //UI(int s);

	void iconExplode(Icon* icon);
    void setGoal(int i);
    void setBgPicture(int t);
    void setBGM(int p);


    int goalScore=0;
    int score =0;           //分数
public slots:
	void iconClicked();
	void iconReleased();
	void iconSwap(int dir);
	void timeUp();
	void on_pushButton_clicked();
	void on_restart_clicked();


private slots:

    void on_musicButton_clicked();

    void on_action_H_triggered();

    void on_HintButton_clicked();

private:
	Ui::UIClass ui;
	Icon*** icons;
	Number** number;
    void AddScore(int);
    void setScore();
	Music music1, music2;
	MyHelper helper;
    int random = 0;
    bool isPause;
    QIcon musicicon;
    QIcon musicicon2;
	QFrame* frame;
	void drop_tmp(int row, int col);
	void initIcons(int row, int column);	
	void artword(int number, int sort);
	void initnum(int num, int sort);
    bool swapAndDelete(int row1, int column1, int row2, int column2);
    void swap(int row1, int column1, int row2, int column2);

	std::vector<Icon*> getPoints(int row, int column);
	void sleep(int sleepTime);

	QTimer* timer;
	QEventLoop Wait;
	int m_time;
	bool iswait = false;
	QString initime;
	QStack <int> stk;
	bool CheckMapDead(int,int);
    std::vector<Icon*> Hint(int,int );
    bool DropUnit(int row, int column);
    void RandomAdd(int row, int column);  
    bool AutoDelete(int row,int column);
	void freshMap(int row, int column);
    bool ifWin();
    void gameOver();
    void updateScore();

public:
    OrderView* v;
    playerInfo info;
	int TIME = 50;
    Help* help;
    int scale=10;

signals:
    void sendGameOver(int);


protected:

     void closeEvent(QCloseEvent *event);  //重写QWidget的虚函数

};
