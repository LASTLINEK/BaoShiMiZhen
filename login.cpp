#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "playerinfo.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //info.printData();


    if(info.findUser(ui->userLine->text(),ui->passLine->text()))
    {
        QMessageBox::about(NULL,QString::fromLocal8Bit("message"),QString::fromLocal8Bit("Log in successfully!     "));
        user a = info.getCurrent();
        //qDebug() << a.username << a.password << a.score;

        play = new UI;
        play->v = new OrderView;
        play->v->setData(info.lis);
        play->show();                       //打开游戏界面
        this->close();
    }
    else
    {
        QMessageBox::about(NULL,QString::fromLocal8Bit("message"),QString::fromLocal8Bit("Log in failed!     "));
    }


}

void Login::on_pushButton_2_clicked()
{
    if(info.addUser(ui->userLine->text(),ui->passLine->text()))
    {
        QMessageBox::about(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("注册成功！     "));

    }
}

void Login::on_pushButton_3_clicked()
{
    play = new UI;
    play->v = new OrderView;
    play->v->setData(info.lis);
    play->show();                       //打开游戏界面
    this->close();
}
