#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "choosedif.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    void setName(QString name);
    void setCurScore(int s);

private slots:
    void on_BtnMode1_clicked();
    void on_BtnMode2_clicked();
    void on_BtnOverview_clicked();
    void on_BtnSetting_clicked();
    void receiveData(QString data);

    void setScore(int score);
    void setGoal(int g);
    void setBG();

private:
    Ui::Menu *ui;
    UI* play;
    int backgroudMusic=0;  //背景音乐
    int theme=0;  //主题
    QString crName;
    int crScore=0;

    playerInfo* info;
    OrderView* od;
    ChooseDif* cd;

public slots:
};

#endif // MENU_H
