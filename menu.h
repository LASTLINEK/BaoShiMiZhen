#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "UI.h"

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


private:
    Ui::Menu *ui;
    UI* play;
    int backgroudMusic;  //背景音乐
    int theme;  //主题
    QString crName;
    int crScore;

    playerInfo info;
    OrderView* od;

public slots:
};

#endif // MENU_H
