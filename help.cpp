#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
//    ui->textEdit->viewport()->setAutoFillBackground(false);
//    ui->textEdit->setReadOnly(true);
}

Help::~Help()
{
    delete ui;
}
