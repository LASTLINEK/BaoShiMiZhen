#include "setting.h"
#include "ui_setting.h"
#include <iostream>

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    QImage _image;
    _image.load("settingbg.jpg");
     setAutoFillBackground(true);   // 这个属性一定要设置
     QPalette pal(palette());
     pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation)));
     setPalette(pal);
     this->setWindowTitle("主题设置");
     groupButton1=new QButtonGroup(this);
     groupButton1->addButton(ui->RBtn1,0);
     groupButton1->addButton(ui->RBtn2,1);
     groupButton1->addButton(ui->RBtn3,2);
     groupButton1->addButton(ui->RBtn4,3);
     ui->RBtn1->setChecked(true); //默认选中
     select_1 = 0;
     groupButton2=new QButtonGroup(this);
     groupButton2->addButton(ui->RBtn5,0);
     groupButton2->addButton(ui->RBtn6,1);
     ui->RBtn5->setChecked(true);
     select_2 = 0;
}

Setting::~Setting()
{
    delete ui;
}
void Setting::on_BtnConfirm_clicked(){
    select_1 = groupButton1->checkedId();
    select_2 = groupButton2->checkedId();
    emit sendData((std::to_string(select_1)+" "+std::to_string(select_2)).c_str());
    this->close();
}
void Setting::on_BtnCancel_clicked(){
    emit sendData("NO");
    this->close();
}
