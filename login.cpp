#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "playerinfo.h"


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(&lgon,&Logon::sendMessage,this,&Login::receiveMsg);

    QImage _image;      //背景图片设置
    _image.load("logbg.jpg");
    setAutoFillBackground(true);   // 这个属性一定要设置
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation)));
    setPalette(pal);

    QPalette pa;                  //lable字体颜色
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->label_3->setPalette(pa);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()         //登陆
{
    //info.printData();
    QString name = ui->userLine->text();
    QString pass = ui->passLine->text();

    if(info.findUser(name))
    {
        if(info.findUser(name,pass))
        {
            QMessageBox::about(NULL,tr("提示"),tr("登陆成功！  "));

            user a = info.getCurrent();
            qDebug() << a.username << a.password << a.score;

            menu.show();
            menu.setName(name);
            menu.setCurScore(a.score);

            this->close();
        }
        else
        {
            QMessageBox::about(NULL,tr("登陆失败"),tr("用户名或密码不正确！   "));
        }
    }
    else
    {
        QMessageBox::about(NULL,tr("登陆失败"),tr("该用户不存在！   "));
    }
}

void Login::on_pushButton_2_clicked()      //注册
{
    lgon.show();
}

void Login::on_pushButton_3_clicked()      //跳过
{
//    play = new UI;
//    play->v = new OrderView;
//    play->v->setData(info.lis);
//    play->show();                       //打开游戏界面
//    this->close();

//    OrderView* od;
//    od = new OrderView;

//    info.updateScore("zk",33);
//    info.addUser("UZI","123123");

//    od->setData(info.lis);
//    od->show();

    menu.show();
    this->close();

    //menu.setName(name);
    //menu.setCurScore(a.score);
}

void Login::receiveMsg(QString name, QString pass)
{
    if(info.addUser(name,pass))
    {
        QMessageBox::about(NULL,tr("提示"),tr("注册成功！  "));
        lgon.close();
    }
    else
    {
        QMessageBox::about(NULL,tr("注册失败"),tr("用户名已存在！  "));
    }
}
