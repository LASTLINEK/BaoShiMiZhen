#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "playerinfo.h"
#include "setting.h"
#include <iostream>
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setWindowTitle("Menu");
    QImage _image;
    _image.load("menubg.jpg");
    setAutoFillBackground(true);   // 这个属性一定要设置
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    ui->BtnMode1->QPushButton::setFlat(true);
    ui->BtnMode2->QPushButton::setFlat(true);
    ui->BtnSetting->QPushButton::setFlat(true);
    ui->BtnOverview->QPushButton::setFlat(true);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::setName(QString name)
{
    crName = name;
}

void Menu::setCurScore(int s)
{
    crScore = s;
}
void Menu::on_BtnMode1_clicked(){


}
void Menu::on_BtnMode2_clicked(){
   play = new UI;
   connect(play,SIGNAL(sendGameOver(int)),this,SLOT(setScore(int)));
   play->show();                       //打开游戏界面
}
void Menu::on_BtnOverview_clicked(){

    od = new OrderView;
    od->setData(info.lis);
    od->show();
}
void Menu::on_BtnSetting_clicked(){
    Setting *setting;
    setting = new Setting;
    connect(setting, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    setting->show();
}
void Menu::receiveData(QString data){
    if (data!="NO"){
        backgroudMusic =std::stoi(data.toStdString().substr(0,1));
        theme = std::stoi(data.toStdString().substr(2,1));
    }
    std::cout <<"backgroudMusic "<<backgroudMusic<<"\n";
    std::cout <<"theme "<<theme<<"\n";
}

void Menu::setScore(int score)
{
    if(score > crScore)
    {
        info.updateScore(crName,score);
        crScore = score;
    }
    qDebug() << "new score: " << score;
}
