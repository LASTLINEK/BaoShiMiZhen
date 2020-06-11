#include "choosedif.h"
#include "ui_choosedif.h"

ChooseDif::ChooseDif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseDif)
{
    ui->setupUi(this);
}

ChooseDif::~ChooseDif()
{
    delete ui;
}

void ChooseDif::on_pushButton_clicked()
{
    int goal=0;
    if(ui->radioButton->isChecked())
        goal = 100;
    else if(ui->radioButton_2->isChecked())
        goal = 200;
    else if(ui->radioButton_3->isChecked())
        goal = 300;
    emit sendGoal(goal);

    this->close();
}
