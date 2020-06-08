#include "logon.h"
#include "ui_logon.h"

Logon::Logon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logon)
{
    ui->setupUi(this);
    ui->w1Label->hide();
    ui->w11Lable->hide();
    ui->r1Label->hide();
    ui->w2Label->hide();
    ui->w22Lable->hide();
    ui->r2Label->hide();

    QImage _image;      //背景图片设置
    _image.load("logonbg.jpg");
    setAutoFillBackground(true);   // 这个属性一定要设置
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation)));
    setPalette(pal);
}

Logon::~Logon()
{
    delete ui;
}

void Logon::on_passLine_textChanged(const QString &arg1)
{
    if(arg1.length()<6)
    {
        ui->w1Label->show();
        ui->w11Lable->show();
        ui->r1Label->hide();
    }
    else
    {
        ui->w1Label->hide();
        ui->w11Lable->hide();
        ui->r1Label->show();
    }

    on_pass2Line_textChanged(ui->pass2Line->text());

}

void Logon::on_pass2Line_textChanged(const QString &arg1)
{
    if(arg1 == ui->passLine->text())
    {
        ui->w2Label->hide();
        ui->w22Lable->hide();
        ui->r2Label->show();

    }
    else
    {
        ui->w2Label->show();
        ui->w22Lable->show();
        ui->r2Label->hide();
    }
}

void Logon::on_logonBtn_clicked()
{
    if(ui->r1Label->isVisible() && ui->r2Label->isVisible())
    {
        emit sendMessage(ui->lineEdit->text(),ui->passLine->text());
    }
}
